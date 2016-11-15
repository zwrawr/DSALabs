# Lab 9 : Hash Tables

## Introduction

    In the last lecture we introduced a new abstract data type called an associative array. Associative arrays store (key, value) pairs where the keys are used to access the associated value; similar to how indexes are used to access entities in standard arrays. In the lecture we also covered two possible implementations of associative arrays; direct address tables and hash tables. Direct address tables comprise of an array large enough to store all possible (key, value) pairs. The key of each (key, value) pair is used by a one-to-one function which determines a unique index in the direct address table. Direct address tables have the property that insert, search and remove operations take O(1) time, but with the significant limitation that they often use substantially more memory than is necessary. Hash tables comprise of a array of size m and determine where to store each (key, value) pair using a hash function. The key of each (key, value) pair is used by a many-to-one hash function which determines the index in the hash table. This many-to-one mapping means that two distinct keys can generate the same index. When two or more (key, value) pairs are inserted into the same index a collision is said to have occurred. Collision must be accommodated by the hash table using methods such as chaining. Hash functions make the assumption that the number of (key, value) pairs to store is much smaller than the number of possible (key, value) pairs. If a uniform hash function is used, operations take O(1 + n/m) time; where n is the number of (key, value) pairs to store and m is the size of the hash table. This represents a compromise between memory complexity and time complexity; as m is increased the time complexity decrease and the memory complexity increases. In this lab we will be implementing the associative array abstract data type using a hash table data structure.

[Lab 9 Script ](http://www.elec.york.ac.uk/internal_web/meng/yr2/modules/DSA/DSA/Labs/Scripts/Lab9-HashTables.pdf)