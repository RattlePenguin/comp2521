# Introduction
Hash tables allow us to store key-value mappings and search for them in $O(1)$ time.
We hash a given key to ensure it fits within our hash table.

There are three ways to solve collisions in a hash table:
- Linear Probing (contiguous)
- Separate Chaining (linked list)
- Double Hashing

Be aware of implementation differences in lookup, insertion and deletion for these.

**Using** hash tables is extremely simple!
However, their implementations may be difficult.
Please practise stepping through each implementation and being comfortable with them.

# Reminders
- Make sure to get all your lab marking done soon!

# Topics
- Hash Tables
    - Hashing, Lookup, Insertion, Deletion (impl specific)
    - Linear Probing
    - Separate Chaining
    - Double Hashing

## Hash Tables
Hash tables are an important data structure.
If order does not matter, storing items in a hash table often optimises algorithms by factors of $n$.
It is an associative data structure, allowing us to map key-value pairs and perform efficient lookup by key.

We want to use an array to act as our hash table, so that we can access values in $O(1)$ time.
However, remember that our indices can only be from 0 to n - 1!
The hash function is what allows us to input any given key and still store it within index bounds.
For example when storing integers as keys:
```
hash(HashTable ht, int x) {
    return x % HashTableSize(ht);
}
```
No matter what key is given, the output of the hash function will be a result between `0` and `size - 1`.

### Collisions
Collisions occur when different keys hash to the same index.
As the hash table becomes more occupied, collisions become more likely to occur.
A collision prevents us from determining whether the value stored at a certain index belongs to the correct key.

The load factor $\alpha$ is the ratio of the number of elements to the number of slots.
$$\alpha = \frac{n}{m}$$

Once the load factor reaches a certain threshold (e.g. 0.50) the hash table is usually doubled in size.

### Linear Probing
### Separate Chaining
### Double Hashing
