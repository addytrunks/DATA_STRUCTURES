#include <stdio.h>

int pageFaultsFIFO(int pages[], int n, int frames);
int pageFaultsLRU(int pages[], int n, int frames);
int pageFaultsOptimal(int pages[], int n, int frames);
int pageFaultsMRU(int pages[], int n, int frames);

int main()
{
    int pages[] = {6, 1, 1, 2, 0, 3, 4, 6, 0, 2, 1, 2, 1, 2, 0, 3, 2, 1, 2, 0};
    int n = sizeof(pages) / sizeof(pages[0]);
    int frames = 4;

    printf("Number of Page Faults for FIFO: %d\n", pageFaultsFIFO(pages, n, frames));
    printf("Number of Page Faults for LRU: %d\n", pageFaultsLRU(pages, n, frames));
    printf("Number of Page Faults for Optimal: %d\n", pageFaultsOptimal(pages, n, frames));
    printf("Number of Page Faults for MRU: %d\n", pageFaultsMRU(pages, n, frames));

    return 0;
}

// FIFO Page Replacement
int pageFaultsFIFO(int pages[], int n, int frames)
{
    int frame[frames], pageFaults = 0, index = 0;

    for (int i = 0; i < frames; i++)
        frame[i] = -1; // Initialize frames

    for (int i = 0; i < n; i++)
    {
        int pageFound = 0;

        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == pages[i])
            {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound)
        {
            frame[index] = pages[i];
            index = (index + 1) % frames;
            pageFaults++;
        }
    }

    return pageFaults;
}

// LRU Page Replacement
int pageFaultsLRU(int pages[], int n, int frames)
{
    int frame[frames], recent[frames], pageFaults = 0, minIndex, frameCount = 0;

    // Initialize frame and recent arrays
    for (int i = 0; i < frames; i++)
    {
        frame[i] = -1;
        recent[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        int pageFound = 0;

        // Check if the page is already in the frame
        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == pages[i])
            {
                recent[j] = i; // Update the last used index of the page
                pageFound = 1;
                break;
            }
        }

        // If page is not found in frame, we have a page fault
        if (!pageFound)
        {
            // If there is still space in the frame, add the page
            if (frameCount < frames)
            {
                frame[frameCount] = pages[i];
                recent[frameCount] = i;
                frameCount++;
            }
            // Find the least recently used page index
            else
            {
                minIndex = 0;
                for (int j = 0; j < frames; j++)
                {
                    // Ensure we select a valid replacement index if recent[j] is still -1
                    if (recent[j] < recent[minIndex])
                        minIndex = j;
                }

                // Replace the least recently used page with the new page
                frame[minIndex] = pages[i];
                recent[minIndex] = i; // Update recent for the new page
            }
            pageFaults++; // Increment page fault count
        }
    }

    return pageFaults;
}

// Optimal Page Replacement
int pageFaultsOptimal(int pages[], int n, int frames)
{
    int frame[frames], pageFaults = 0, frameCount = 0;

    for (int i = 0; i < frames; i++)
        frame[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int pageFound = 0;

        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == pages[i])
            {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound)
        {
            if (frameCount < frames)
            {
                frame[frameCount] = pages[i];
                frameCount++;
            }
            else
            {

                int farthest = i, index = -1;

                for (int j = 0; j < frames; j++)
                {
                    int next = i + 1;
                    while (next < n && pages[next] != frame[j])
                        next++;
                    if (next > farthest)
                    {
                        farthest = next;
                        index = j;
                    }
                }

                if (index == -1)
                    index = 0;
                frame[index] = pages[i];
            }
            pageFaults++;
        }
    }

    return pageFaults;
}

// MRU Page Replacement
int pageFaultsMRU(int pages[], int n, int frames)
{
    int frame[frames], recent[frames], pageFaults = 0, frameCount = 0;

    for (int i = 0; i < frames; i++)
    {
        frame[i] = -1;  // Initialize frame
        recent[i] = -1; // Initialize recent array
    }

    for (int i = 0; i < n; i++)
    {
        int pageFound = 0;

        // Check if the page is already in the frame
        for (int j = 0; j < frames; j++)
        {
            if (frame[j] == pages[i])
            {
                pageFound = 1;
                recent[j] = i; // Update most recent use
                break;
            }
        }

        // If page is not found, handle page fault
        if (!pageFound)
        {
            if (frameCount < frames) // Still space in frames
            {
                frame[frameCount] = pages[i];
                recent[frameCount] = i;
                frameCount++;
            }
            else
            {
                // Find the most recently used (MRU) page
                int maxIndex = 0;
                for (int j = 1; j < frames; j++)
                {
                    if (recent[j] > recent[maxIndex])
                        maxIndex = j;
                }

                // Replace the MRU page with the new page
                frame[maxIndex] = pages[i];
                recent[maxIndex] = i;
            }

            pageFaults++; // Increment page faults only on a replacement
        }
    }

    return pageFaults;
}