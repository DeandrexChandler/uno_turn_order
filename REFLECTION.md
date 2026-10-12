### 1. Why does concat only need to work between two lists of the same representation? What would you have to do differently, or what would go wrong, if you tried to make it work between a LinkedList and an ArrayList?

- Because ArrayList and LinkedList stores elements differently. ArrayList uses an array to store pointers and LinkedList connects nodes, because of this, it would cause conflict when trying to concat them directly. To make it work, you would have to iterate through one list and store them into the opposing list time so that concatination can work safely.

### 2. Walk through reverse() on your linked list: name the three pointers you need alive at once, and explain why losing track of any one of them mid-loop corrupts the list.

- The 3 pointer used in LinkedList reverse() are prev, current, and next. Prev points to the node before current and next stores the next nodes in front of current, so that when i swap prev and current, i dont lose the rest of the list.

### 3. addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for position in each, and what does your implementation do if a caller passes a position outside it?

- 0 to size for addAnywhere and 0 to size-1 for deleteAnywhere. If a caller passes a position outside, the code would return "Outside of range."

### 4. n LinkedList::concat, why did you need to walk to the end of the list first, when addFront and deleteFront never needed to? What would change about concat’s performance if LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere if you added one back?

- LinkedList's concat needed to walk to the end of the list so that it can connect that end to the beginning of the other list's. add and deleteFront never needed to because they had head\_ already pointing to the front of the list. Concat would perform faster but would need to update tail\_ for every operation.

### 5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what has to shift and in which direction, and why shifting in the wrong direction would overwrite data you still need.

- In deleteAnywhere, it deletes the element at the desired position, then shifts elements from the front (to the left) to fill up that empty space and decrement size by 1. If it shifted from the back, it would overwite data i still need because I haven't move it yet.

### 6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of play, and explain what would visibly break in the game if that call were missing.

- line 43 "players->reverse();" changes the direction of the play. If this line was to be removed, line 48 "players->deleteAnywhere(1);" would remove benyamin instead of Deandre.

---

**Ai Disclosure:** Claude was used to final check if work fulfilled requirements and spellcheck typos. I types and committed all code myself.
