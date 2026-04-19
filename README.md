# Smart Search Autocomplete System

This is a C++ based search system that provides suggestions based on user input prefix.

## Features
- Prefix-based search using Binary Search
- Frequency-based ranking using HashMap
- Displays top 3 relevant suggestions

## Data Structures Used
- Vector (Array)
- HashMap (unordered_map)
- Sorting
- Binary Search

## How it works
- Words are stored in sorted order
- Binary search is used to find matching prefixes efficiently
- Results are ranked based on search frequency

## Complexity
- Search: O(log n + k log k)
