class Solution {
public:
    bool reorderedPowerOf2(int N)
    {
        string input = to_string(N);
        sort(input.begin(), input.end());
        for(int i = 0 ; i < 30; i++)
        {
            string original = to_string(1 << i);
            sort(original.begin(), original.end());
            if(original == input)
            {
                return true;
            }
        }
        return false;
    }
};
/*
The easiest way to check if two things are shuffled versions of each other, which is what this problem is asking us to do, is to sort them both and the compare the result.

In that sense, the easiest solution here is to do exactly that: we can convert N to an array of its digits, sort it, then compare that result to the result of the same process on each power of 2.

Since the constraint upon N is 10e9, we only need to check powers in the range [0,29].

*/
