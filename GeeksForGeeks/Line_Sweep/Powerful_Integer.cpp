class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // code here
        // Step 1: Initialize a map to store the changes in active interval count.
        // The key is the point on the number line, and the value is the
        // change (+1 for interval start, -1 for interval end+1).
        // std::map automatically keeps keys (points) sorted, which is crucial for the sweep line.
        map<int, int> delta;

        // Populate the delta map with events.
        // For each interval [start, end]:
        // Increment count at 'start' (interval begins).
        // Decrement count at 'end + 1' (interval effectively ends just before this point).
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            delta[start]++;       // Event: interval starts, increase count
            delta[end + 1]--;     // Event: interval ends, decrease count from end+1 onwards
        }

        // Initialize variables for the sweep line process.
        int currentActiveIntervals = 0; // Tracks how many intervals are currently active.
        int maxPowerfulInteger = -1;    // Stores the maximum powerful integer found so far.
                                        // Initialized to -1, assuming problem constraints allow.
                                        // If no powerful integer exists, -1 will be returned.

        // Edge case: If no intervals are provided, delta map will be empty.
        // The loop will not execute, and maxPowerfulInteger will remain -1, which is correct.
        if (delta.empty()) {
            return -1;
        }

        // Initialize prevPoint with the very first event point from the map.
        // This is used to define segments between consecutive event points.
        int prevPoint = delta.begin()->first;

        // Step 2: Traverse the sorted event points in the delta map (sweep line).
        // For each (point, change) pair:
        for (auto const& [point, change] : delta) {

            // Phase A: Evaluate the segment from 'prevPoint' up to 'point - 1'.
            // This segment was active with 'currentActiveIntervals' BEFORE the 'change' at 'point' is applied.
            //
            // Condition breakdown:
            // 1. prevPoint != delta.begin()->first: Ensures we're not evaluating a segment
            //    "before" the very first event point. For the first iteration, this is false.
            // 2. prevPoint < point: Ensures there is an actual segment [prevPoint, point-1] to evaluate.
            //    If prevPoint == point, there's no such segment (e.g., when multiple events are at same point).
            if (prevPoint != delta.begin()->first && prevPoint < point) {
                // If the number of active intervals in this segment was >= k,
                // then all integers from prevPoint to point-1 are powerful.
                // Since we want the MAX powerful integer, point-1 is the largest candidate
                // from this segment.
                if (currentActiveIntervals >= k) {
                    maxPowerfulInteger = std::max(maxPowerfulInteger, point - 1);
                }
            }

            // Phase B: Apply the change in count at the current 'point'.
            // 'currentActiveIntervals' now reflects the count *at* and *after* 'point'.
            currentActiveIntervals += change;

            // Phase C: Evaluate the current 'point' itself.
            // After applying the change, if the new 'currentActiveIntervals' is >= k,
            // then 'point' itself is a powerful integer.
            // This covers cases where 'point' is the start of a new powerful segment.
            if (currentActiveIntervals >= k) {
                maxPowerfulInteger = std::max(maxPowerfulInteger, point);
            }

            // Update 'prevPoint' for the next iteration.
            // The current 'point' becomes the 'prevPoint' for the next segment.
            prevPoint = point;
        }

        // Step 3: Return the maximum powerful integer found.
        return maxPowerfulInteger;
    }
};