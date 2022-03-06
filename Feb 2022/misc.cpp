/* 
Amazon student program (SDE-1) Hiring -- 
Q1 . A hero is fighting a war . Given a list of stages which can be overcome by going to each one of them and 
then the power of robot reduces by strength at that stage and we are given an armour of power P which we can use at most one stage.
Also at any point of time during the game and after the game the strength of the robot should always be greater than zero.
Determine the minimum power of the robot which should be there at the starting of the game.

Expected time complexity : 1<=N<=10^5

Solution : sort the array and find the sum of the array ,
also find the  lower_bound on the vector for the armour power and answer would be 
sum-val(iterator of lower_bound)+abs(armour-iterator of lower_bound)
*/


/*Q2. Given an array of numbers , determine the minimum no of groups into which the array can be divided such that difference 
between any pair of numbers in any group is atmost K. 
N=7  array = [1,3,5,6,8,9,13] and k = 4

Time complexity : 1<=N<=10^5
                  1<=A[i]<=10^7

Answer : [1,3,5] ,[6,8,9] ,[13] are the 3 minimum no of groups. 

Solution : would be keep incrementing cnt variable and we would be finding until
  el = ar[0]
  while( upper_bound(el+k) != vec.end())
  {
        el = el+k;
        cnt++;
  }
  print(cnt)
*/



/* 
Question : 

Assume english alphabet letters can be given the values as a=1, b=2, c=3 and so on.
Given the two numbers n and k, where n is number of letters and k is the sum of their values, 
find the lexicographically smallest string with n letters and sum of letters as k.
Example 1: Input: n=3, k=27 Output: aay
Example 2: Input: n=5, k=73 Output: aaszz

[ GFG Medium question ] 
 */
