# linux_project

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/93113b41568d4327a17b3de1de3d0d8a)](https://app.codacy.com/manual/99002644/linux_project?utm_source=github.com&utm_medium=referral&utm_content=99002644/linux_project&utm_campaign=Badge_Grade_Settings)

Person1 and person2  arel used to checking the fridge . If milk run out, he or she will go to market to buy milk. The refrigerator  is small such that  only one bottle of milk can be put in it at a time.

Two programs are written to simulate the above situation.When process person1 or person2  buys a bottle of milk, it writes  "milk" to a file fridge (the file is empty at the begining).
Person1 and person2 decide to lock the fridge. There is only one key to open the lock, the one who gets the key can check the refrigerator. 

run like this:
gcc person1.c  -o person1
gcc person2.c -o person2
													
./person1 & ./person2

