for the values ,0,2,4,6,8 we have some unique values for each of them
0 - 'z'
2 - 'w'
4 - 'u'
6 - 'x'
8 - 'g'
​
now apart from these values , we are left with 1,3,5,7,9
these numbers also have some unique number if we dont take the above numbers into account
1 - 'o' ==>> that means we have to find the frequency of 'o' and subtract the frequency of 'o' occuring in above numbers. mp['o'-'a'] - mp['z'-'a']-mp['t'-'a']-mp['u'-'a']
3 - 'r' ==>> count['r'-'a'] - num['u'-'a']
5 - 'f' ==>> count['f'-'a'] - num['u'-'a']
7 - 's' ==>> count['v'-'a'] - num['x'-'a']
9 - 'n' ==>> count['n'-'a'] - num['o'-'a']- num['s'-'a']
​
it is given that s is valid. we just need to traverse the num vector.
​