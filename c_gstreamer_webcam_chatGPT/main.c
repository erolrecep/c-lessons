#include <gst/gst.h>

int main(int argc, char *argv[]) {
    GstElement *pipeline, *source, *sink;
    GstCaps *caps;
    GstBus *bus;
    GstMessage *msg;
    GstStateChangeReturn ret;
    gboolean terminate = FALSE;

    /* Initialize GStreamer */
    gst_init(&argc, &argv);

    /* Create elements */
    source = gst_element_factory_make("v4l2src", "source");
    sink = gst_element_factory_make("ximagesink", "sink");

    /* Create empty pipeline */
    pipeline = gst_pipeline_new("webcam-pipeline");

    /* Check that elements are created successfully */
    if (!pipeline || !source || !sink) {
        g_printerr("Not all elements could be created.\n");
        return -1;
    }

    /* Build the pipeline */
    gst_bin_add_many(GST_BIN(pipeline), source, sink, NULL);
    if (gst_element_link(source, sink) != TRUE) {
        g_printerr("Elements could not be linked.\n");
        gst_object_unref(pipeline);
        return -1;
    }

    /* Set up the camera */
    caps = gst_caps_new_simple("video/x-raw",
        "width", G_TYPE_INT, 640,
        "height", G_TYPE_INT, 480,
        "framerate", GST_TYPE_FRACTION, 30, 1, NULL);
    g_object_set(G_OBJECT(source), "device", "/dev/video0", NULL);
    g_object_set(G_OBJECT(source), "caps", caps, NULL);
    gst_caps_unref(caps);

    /* Set the pipeline to "playing" state */
    ret = gst_element_set_state(pipeline, GST_STATE_PLAYING);
    if (ret == GST_STATE_CHANGE_FAILURE) {
        g_printerr("Unable to set the pipeline to the playing state.\n");
        gst_object_unref(pipeline);
        return -1;
    }

    /* Wait until error or EOS */
    bus = gst_element_get_bus(pipeline);
    do {
        msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE,
            GST_MESSAGE_ERROR | GST_MESSAGE_EOS | GST_MESSAGE_STATE_CHANGED);
        switch (GST_MESSAGE_TYPE(msg)) {
            case GST_MESSAGE_ERROR:
                g_printerr("Error received from element %s: %s\n",
                    GST_OBJECT_NAME(msg->src), msg->structure->data);
                g_printerr("Debugging information: %s\n",
                    gst_structure_to_string(msg->structure));
                terminate = TRUE;
                break;
            case GST_MESSAGE_EOS:
                g_print("End-Of-Stream reached.\n");
                terminate = TRUE;
                break;
            case GST_MESSAGE_STATE_CHANGED:
                /* We are only interested in state-changed messages from the pipeline */
                if (GST_MESSAGE_SRC(msg) == GST_OBJECT(pipeline)) {
                    GstState old_state, new_state, pending_state;
                    gst_message_parse_state_changed(msg, &old_state, &new_state, &pending_state);
                    g_print("Pipeline state changed from %s to %s.\n",
                        gst_element_state_get_name(old_state), gst_element_state_get_name(new_state));
                }
                break;
            default:
                /* We should not reach here */
                g_printerr("Unexpected message received.\n");
                break;
        }
        gst_message_unref(msg);
    } while (!terminate);

    /* Free resources */
    gst_object_unref(bus);
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);
    return 0;
}
