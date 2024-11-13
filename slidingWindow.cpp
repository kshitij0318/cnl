#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <random>

using namespace std;

int WINDOW_SIZE = 4;
int FRAME_COUNT = 10;
vector<bool> ACK(FRAME_COUNT, false); // Acknowledgment array

void sendFrame(int frame)
{
    cout << "Sending frame " << frame << endl;
}

void receiveACK(int frame)
{
    cout << "Acknowledgment received for frame " << frame << endl;
    ACK[frame] = true;
}

void selectiveRepeat()
{
    int sendBase = 0;
    int nextFrame = 0;

    while (sendBase < FRAME_COUNT)
    {
        // Send frames within the window
        while (nextFrame < sendBase + WINDOW_SIZE && nextFrame < FRAME_COUNT)
        {
            if (!ACK[nextFrame])
            {
                sendFrame(nextFrame);
            }
            nextFrame++;
        }

        // Randomly acknowledge frames for demonstration purposes
        for (int i = sendBase; i < sendBase + WINDOW_SIZE && i < FRAME_COUNT; ++i)
        {
            if (!ACK[i] && rand() % 2 == 0)
            { // Simulating random ACK receipt
                receiveACK(i);
            }
        }

        // Slide window if first frame in the window is acknowledged
        while (sendBase < FRAME_COUNT && ACK[sendBase])
        {
            sendBase++;
        }
    }
    cout << "All frames sent and acknowledged (Selective Repeat)" << endl;
}
void goBackN(int frameCount, int windowSize)
{
    vector<bool> ACK(frameCount, false);
    int base = 0;
    int nextSeqNum = 0;

    while (base < frameCount)
    {
        // Send frames within the window
        while (nextSeqNum < base + windowSize && nextSeqNum < frameCount)
        {
            cout << "Sending frame " << nextSeqNum << endl;
            nextSeqNum++;
        }

        // Randomly simulate acknowledgment receipt
        if (rand() % 2 == 0 && base < frameCount)
        { // 50% chance for ACK
            cout << "Acknowledgment received for frame " << base << endl;
            ACK[base] = true;
            base++; // Move base to the next unacknowledged frame
        }
        else
        {
            // If ACK not received, resend from base frame
            cout << "No ACK for frame " << base << ". Resending from frame " << base << endl;
            nextSeqNum = base;
        }

       
    }
    cout << "All frames sent and acknowledged (Go-Back-N)" << endl;
}

int main()
{
    cout << "Starting Selective Repeat Protocol:\n";
    selectiveRepeat();

    cout << "\nStarting Go-Back-N Protocol:\n";
    goBackN(FRAME_COUNT, WINDOW_SIZE);

    return 0;
}