Heap h;
Item it;
h = heapNew();

heapInsert(h, 10);
heapInsert(h,  5);
heapInsert(h, 15);
heapInsert(h , 3);
heapInsert(h, 16);
heapInsert(h, 13);
heapInsert(h,  6);
it = heapDelete(h);
heapInsert(h,  2);
it = heapDelete(h);
it = heapDelete(h);
it = heapDelete(h);
it = heapDelete(h);
it = heapDelete(h);
