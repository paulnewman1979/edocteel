#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

https:leetcode.com/problems/find-median-from-data-stream/

struct Node{
    void Node(int value) {
        this.value = value;
        left = NULL;
        right = NULL;
    }
    int value;
    Node* left;
    Node* right;
};

class MedianFinder {
    public:
        MedianFinder() {
            left_size = 0;
            right_size = 0;
            left_value = 0;
            right_value = 0;
            medium_value = 0;
        }

        // Adds a number into the data structure.
        void addNum(int num) {
            if (num >= medium_value) {
                insert_right(value);
                right_size ++;
                if (right_size == left_size + 2)
                {
                    left_value = pop_from_right();
                    left_size ++;
                    right_size --;
                }
            }
            else {
                insert_left(value);
                left_size ++;
                if (left_size == right_size + 2)
                {
                    pop_from_left();
                }
            }

            if (left_size == 0) {
                medium = num;
            }
            else {

            }
        }

        void insert(Node* node, int value) {
            if (node == NULL) {
                node = new Node(value)
            }
            else if (value > node.value) {
                insert(node->right);
            }
            else {
                insert(node->left);
            }
        }

        Returns the median of current data stream
            double findMedian() {
                return medium;
            }

    private:
        int left_size;
        int right_size;
        int left_value;
        int right_value;
        double medium_value;
        Node* left;
        Node* right;
};

//Your MedianFinder object will be instantiated and called as such:
MedianFinder mf;
mf.addNum(1);
mf.findMedian();
