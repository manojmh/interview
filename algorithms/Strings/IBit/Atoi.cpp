/**
https://www.interviewbit.com/problems/atoi/
There are certain questions where the interviewer would intentionally frame the question vague.
The expectation is that you will ask the correct set of clarifications or state your assumptions before you jump into coding.
Implement atoi to convert a string to an integer.
Example :
Input : "9 2704"
Output : 9
Note: There might be multiple corner cases here. Clarify all your doubts using “See Expected Output”.
Questions: Q1. Does string contain whitespace characters before the number?
A. Yes Q2. Can the string have garbage characters after the number?
A. Yes. Ignore it. Q3. If no numeric character is found before encountering garbage characters, what should I do?
A. Return 0. Q4. What if the integer overflows?
A. Return INT_MAX if the number is positive, INT_MIN otherwise. 
Warning : DO NOT USE LIBRARY FUNCTION FOR ATOI.
If you do, we will disqualify your submission retroactively and give you penalty points.
**/
int Solution::atoi(const string A) {
  long long minus = 1;
  long long res = 0;
  for(int i=0; i<A.length(); i++) {
    if(i==0 && A[i] == '-') minus = -1;
    else if(i==0 && A[i] == '+') continue;
    else if(A[i]>='0' && A[i]<='9') {
      res *= 10;
      res += A[i]-'0';
      if(res > INT_MAX)
        break;
    }
    else {
      break;
    }
  }
  //cout << res << endl;
  res *= minus;
  if(res > INT_MAX) return INT_MAX;
  if(res < INT_MIN) return INT_MIN;
  return res;
}
