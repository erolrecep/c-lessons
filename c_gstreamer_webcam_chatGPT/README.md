# Gstreamer for Webcam Stream

---

*Start a gstreamer webcam stream in a Linux distro*

		$ gst-launch-1.0 v4l2src ! video/x-raw, width=640, height=480 ! videoconvert ! autovideosink

*This is the Mac OS version*

		$ gst-launch-1.0 avfvideosrc ! video/x-raw, width=640, height=480 ! videoconvert ! autovideosink

		$ gst-launch-1.0 avfvideosrc device-index=1 ! osxvideosink

		$ gst-launch-1.0 qtkitvideosrc ! video/x-raw, width=640, height=480 ! videoconvert ! autovideosink

		$ gst-launch-1.0 avcapturesrc device-index=0 ! video/x-raw, width=640, height=480 ! videoconvert ! autovideosink

		gst-launch-1.0 syphonviosrc app-name=MyApp ! video/x-raw, width=640, height=480 ! videoconvert ! autovideosink


