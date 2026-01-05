Survival Roguelite Snake: A Multi-Framework Integration

This project is a modern reimagining of the classic "Snake" arcade game, incorporating Roguelite mechanics and a sophisticated Meta-progression economy. It challenges the player to manage biological resources and strategic upgrades between survival rounds.

Framework Interoperability: Engineered a custom bridge between Pygame (Rendering/Game Loop) and Tkinter (Menu/GUI System), managing window lifecycles to prevent memory leaks and thread collisions.

Graph-Based Pathfinding: Implemented a Breadth-First Search (BFS) algorithm using collections.deque to validate game seeds. This ensures every spawned item is reachable, preventing "dead-end" states.

Economic Balancing: Developed a mathematical scaling engine for upgrades using Exponential Growth functions, ensuring long-term game balance and player retention.

State Persistence: Built a manual Data Serialization engine to save and load player progress without external database dependencies.

Procedural Generation: Managed the random distribution of obstacles while maintaining logical consistency via the is_reachable validation set.
