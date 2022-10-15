class Solution {
public:
    bool rotateString(string s, string goal) {
        int numChanges = s.length() - 1;
		while (numChanges--)
		{
			s += s[0];
			s.erase(s.begin());

			if (s == goal)
				return true;
		}

		return false;
    }
};