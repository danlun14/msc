00 READ 99
01 SET 1
02 STORE 98
03 SET 1
04 STORE 97
05 LOAD 99
94 = +1
06 SUB 94
07 JNEG 22
08 LOAD 98
09 SUB 99
10 JB 22
11 LOAD 98
95 = +1
12 ADD 95
13 STORE 96
14 LOAD 97
15 MUL 96
16 STORE 97
17 LOAD 98
95 = +1
18 ADD 95
19 STORE 98
20 JUMP 21
21 JUMP 8
22 LOAD 97
23 DIVIDE 98
24 STORE 97
25 WRITE 97
26 HALT 00