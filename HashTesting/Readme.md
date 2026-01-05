Scalable Hash Table with Quadratic Probing
This project is an exploration of high-efficiency data mapping. It began as a static implementation of a Hash Table using Quadratic
Probing and evolved into a Dynamic Hash Map capable of real-time resizing (Rehashing).

Phase 1 (The Foundation): Implemented an open-addressing scheme with Quadratic Probing to significantly 
reduce the "primary clustering" issues found in simpler linear probing models.

Phase 2 (The Optimization): Refactored the engine to support Dynamic Memory Management. 
The system monitors the "Load Factor" and automatically triggers a Rehash to redistribute data, ensuring O(1) 
average-case lookup time even as the dataset grows.
