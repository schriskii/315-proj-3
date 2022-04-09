X axis = number of elements in the tree prior to the operation.

Perfect straight lines are *probably* the "return trip" of the "drawing head", due to a weird bug that I can't figure out how to fix.



all_sgt.ps / all_avl.ps:
- Show all 5 operations per-implementation.
- Red (0): insert
- Yellow (1): inorder
- Green (2): remove (succeeds to find the element)
- Blue (3): getheight
- Black (4): contains (fails to find the element)

the rest of the .ps files:
- Compare performance on 1 operation between the 2 implementations.
- Red (0): Scapegoat
- Black (1): AVL



Takeaways:

INSERT
- Very fast with either, w/ occasional spikes (perhaps due to having to maintain balance?).
- Slight edge to scapegoat?

INORDER
- No clear advantage, but AVL has larger spikes.

REMOVE
- HUGE advantage to AVL...
- ...but only because my scapegoat implementation didn't come with a remove function, so I had to hack together an awful one that involves in-order traversal.

GETHEIGHT
- Very fast with either, w/ occasional spikes (no idea why there are spikes, though I guess they're tiny...).

CONTAINS
- Very fast with either, w/ occasional spikes.

...so they're, like, the same except for the part where I had to jerry-rig a solution.
