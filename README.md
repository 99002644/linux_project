# linux_project

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/93113b41568d4327a17b3de1de3d0d8a)](https://app.codacy.com/manual/99002644/linux_project?utm_source=github.com&utm_medium=referral&utm_content=99002644/linux_project&utm_campaign=Badge_Grade_Settings)
![cppcheck-action](https://github.com/99002644/linux_project/workflows/cppcheck-action/badge.svg?branch=master)
![C/C++ CI](https://github.com/99002644/linux_project/workflows/C/C++%20CI/badge.svg?branch=master)


Refrigerator as a shared resource:

Person1 and person2  are used to checking the refrigrtaor . If fridge gets run out of milk, he or she will go to market to buy milk. The refrigerator  is small such that only one bottle of milk can be put in it at a time.

Two programs are written to simulate the above situation.

When process person1 or person2  buys a bottle of milk, it writes  "milk" to a file fridge (the file is empty at the begining).
Person1 and person2 decide to lock the fridge. There is only one key to open the lock, the person who gets the key can open the refrigerator. 
If person1 gets the key, person2 can not open the fridge until person1 releases the key. person1 will release the key until she/he ensures there is milk in fthe refrigerator.semaphore is used to implement the key. 

run like this:

													
./person1 & ./person2

