#include <algorithm>
#include <vector>

int solution(std::vector<int>& A) noexcept
{
    if (A.size() < 3) return 0;

    std::vector<int> peaks(A.size());
    int lastPeak = -1;

    peaks.back() = lastPeak;
    for (int i = static_cast<int>(A.size()) - 2; i != 0; --i)
    {
        if (A[i] > A[i - 1] && A[i] > A[i + 1])
        {
            lastPeak = i;
        }
        peaks[i] = lastPeak;
    }
    peaks.front() = lastPeak;

    int maxFlags = 0;

    for (int i = 1; i * i <= static_cast<int>(A.size()) + i; ++i)
    {
        int nextPeak = peaks.front();
        int flags = 0;
        for (int j = 0; j < i && nextPeak != -1; ++j, ++flags)
        {
            if (nextPeak + i >= static_cast<int>(A.size()))
            {
                nextPeak = -1;
            }
            else
            {
                nextPeak = peaks[nextPeak + i];
            }
        }
        maxFlags = std::max(maxFlags, flags);
    }

    return maxFlags;
}

// 80% slow solution
int slowSolution(std::vector<int>& A) noexcept
{
    if (A.size() < 3) return 0;

    std::vector<bool> peaks(A.size());
    size_t peakctr = 0;
    for (size_t i = 1; i != A.size() - 1; ++i)
    {
        if (A[i - 1] < A[i] && A[i] > A[i + 1])
        {
            peaks[i] = true;
            ++peakctr;
        }
    }

    if (0 == peakctr) return 0;

    auto it = std::find(peaks.begin(), peaks.end(), true);
    size_t first = it - peaks.begin();

    size_t maxFlags = 1;
    for (size_t i = 1; i <= peakctr; ++i)
    {
        size_t flags = 0;
        size_t pos = first;
        while (pos < A.size() && flags < i)
        {
            if (peaks[pos])
            {
                ++flags;
                pos += i;
            }
            else
            {
                ++pos;
            }
        }
        maxFlags = std::max(maxFlags, flags);
    }

    return maxFlags;
}