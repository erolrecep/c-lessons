#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10        // number of arms
#define T 1000      // number of time steps
#define EPSILON 0.001 // probability of exploration

int main(void) {
    double q[N] = {0};     // estimated reward for each arm
    int n[N] = {0};        // number of times each arm has been pulled
    int action, reward, t;

    srand(time(NULL));     // initialize random seed

    for (t = 0; t < T; t++) {
        // choose action based on epsilon-greedy policy
        if ((double) rand() / RAND_MAX < EPSILON) {
            action = rand() % N;    // explore
        } else {
            // exploit: choose action with highest estimated reward
            int max_action = 0;
            for (int i = 1; i < N; i++) {
                if (q[i] > q[max_action]) {
                    max_action = i;
                }
            }
            action = max_action;
        }

        // get reward for chosen action (assume normal distribution with mean q_star and variance 1)
        double q_star = 1 + (double) rand() / RAND_MAX;
        reward = (double) rand() / RAND_MAX < q_star ? 1 : 0;

        // update estimates of reward for chosen action
        n[action]++;
        q[action] += (reward - q[action]) / n[action];
    }

    // print estimated reward for each arm
    printf("Estimated reward for each arm:\n");
    for (int i = 0; i < N; i++) {
        printf("Arm %d: %f\n", i, q[i]);
    }

    return 0;
}
