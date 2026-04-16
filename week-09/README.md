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
Linear probing will attempt to insert a key at its correct index first to obtain $O(1)$ lookup.
If it is already occupied, it simply iterates through the array from that index until it finds an empty slot.
To find that same key, we again iterate from the hashed index.
If an empty slot is found, then the key does not exist.

This results in $O(n)$ lookup and insertion in the worst case, when the next empty slot is far away.

Linear probing has two ways to remove keys:
#### Backshift Deletion
Once we find the correct key position, we remove it and reinsert all elements after it until an empty slot.
This makes deletion expensive, but moves keys closer to their intended index improving lookup performance.

#### Tombstone Deletion
Once we find the correct key position, we replace it with a "null" value known as a tombstone.
The next time we insert into the hash table, if we encounter a tombstone we can simply replace it.

When performing lookups, keys may still remain behind tombstones, increasing the time taken.

### Separate Chaining
Separate chaining stores a linked list of elements at each index, like an adjacency list.

This results in $O(n)$ lookup, insertion and deletion in the worst case.

### Double Hashing
Double hashing requires the use of a secondary hash function `hash2`.
When the primary hash function `p = hash1(x)` results in a collision, we calculate `s = hash2(x)`.
The next slots to check will be in the form:

``` c
p + (k * s) % size // where k = 1, 2, 3, ...
```

The size of the hash table should ideally be a prime number to ensure that double hashing visits every index.
