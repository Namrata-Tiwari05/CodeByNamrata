#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool areAnagrams(string &s1, string &s2)
{

  if (s1.size() != s2.size())
  {
    return false;
  }

  // create a hashmap to store
  // character frequencies
  unordered_map<char, int> charCount;

  // count frequency of each
  // character in string s1
  for (char ch : s1)
    charCount[ch] += 1;

  // Count frequency of each
  // character in string s2
  for (char ch : s2)
    charCount[ch] -= 1;

  // check if all frequencies are zero
  for (auto &pair : charCount)
  {
    if (pair.second != 0)
    {
      return false;
    }
  }

  return true;
}

int main()
{

  string s1 = "geeks";
  string s2 = "kseeg";

  if (areAnagrams(s1, s2))
  {
    cout << "true";
  }
  else
  {
    cout << "false";
  }

  return 0;
}