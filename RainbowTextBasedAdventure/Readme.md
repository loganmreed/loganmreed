Multi-Path Narrative Engine: A Python RPG

This is a comprehensive Branching Narrative Engine consisting of over 2,200 lines of Python. It features a sophisticated state-tracking system that manages an inventory, dynamic NPC relationships, and 90+ critical decision points leading to 50 unique endings. Made from an original story.

Dynamic State Management: Implemented a system of "Global Flags" and dictionaries to track inventory and NPC knowledge. Character identifiers update dynamically (e.g., "Unknown NPC" → "Anika") based on player interaction.

Complex Branching Logic: Managed a massive logic tree with two primary storylines (Spy vs. Betrayer) and dozens of fail-states, ensuring 100% path integrity across thousands of lines of dialogue.

Temporal Integration: Utilizes Python’s datetime module to inject the player's real-world time into the narrative, bridging the gap between the modern protagonist and the medieval fantasy setting.
