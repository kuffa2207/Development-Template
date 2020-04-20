# Program development template

* Build system: cmake
* Tests: gtest
* Code style check: cpplint
* Continuous integration: travis-ci


## Merging an upstream repository into your fork (master branch)
```
 git checkout master
 git pull https://github.com/UsovaMA/Development-Template.git master
```
## Update working branch
```
 git checkout <your branch>
 git rebase master
```
This is my irst task with programming language C++ = realization of Term
## Build project with cmake
cmake -DCMAKE_CXX_FLAGS=/D_SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING -G "Visual Studio 15 2017" <path to sourse files>