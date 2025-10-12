#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Job {
    int id;
    int priority;
};

void showJob(const Job& j) {
    cout << "(ID: " << j.id << ", Priority: " << j.priority << ")";
}

int main() {
    queue<Job> jobQueue;
    stack<Job> processStack;

    jobQueue.push({1, 2});
    jobQueue.push({2, 5});
    jobQueue.push({3, 1});
    jobQueue.push({4, 4});
    jobQueue.push({5, 3});

    cout << "Jobs in arrival order:" << endl;;
    queue<Job> tempQueue = jobQueue;
    while (!tempQueue.empty()) {
        showJob(tempQueue.front());
        cout << " ";
        tempQueue.pop();
    }
    cout << endl << endl;

    while (!jobQueue.empty()) {
        Job current = jobQueue.front();
        jobQueue.pop();

        if (processStack.empty()) {
            processStack.push(current);
        } else {
            stack<Job> tempStack;
            while (!processStack.empty() && processStack.top().priority >= current.priority) {
                tempStack.push(processStack.top());
                processStack.pop();
            }

            processStack.push(current);

            while (!tempStack.empty()) {
                processStack.push(tempStack.top());
                tempStack.pop();
            }
        }
    }

    cout << "Execution order (Stack - LIFO by priority):\n";
    while (!processStack.empty()) {
        showJob(processStack.top());
        cout << endl;
        processStack.pop();
    }

    return 0;
}
