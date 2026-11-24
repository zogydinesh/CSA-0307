# Data Structures Assignment 5 – CO5

C11 programs organised by the nine assignment tasks. Each task folder contains its `.c` source and the captured `output.txt` produced by compiling and running it with GCC.

## Folder structure

- `Task01/` – graph model and adjacency-matrix representation.
- `Task02/` – BFS and DFS traversals.
- `Task03/` – Kahn topological sorting for hub dependencies.
- `Task04/` – Dijkstra and Floyd–Warshall shortest paths.
- `Task05/` – Prim and Kruskal minimum spanning trees.
- `Task06/` – BFS using compressed sparse row (CSR) representation.
- `Task07/` – difficult Dijkstra inputs: unreachable destination, negative edge handled with Bellman–Ford, and guarded arithmetic.
- `Task08/` – shortest-path comparison and A* grid search.
- `Task09/` – MST extension and 250,000-junction scalability estimate.

## Compile and run (Windows PowerShell / CMD)

Install GCC (MinGW-w64) and ensure `gcc` is on PATH. Open a terminal in a task folder and run:

```bash
gcc -std=c11 -Wall -Wextra -O2 filename.c -o program.exe
program.exe
```

Example:

```bash
cd Task02
gcc -std=c11 -Wall -Wextra -O2 bfs_dfs.c -o bfs_dfs.exe
bfs_dfs.exe
```

On Linux/macOS, omit `.exe` and run `./program`.

## Notes

- The `output.txt` files are the actual outputs captured from these included programs in the build environment.
- Timing and peak-memory benchmark tables are intentionally not fabricated; measure them on the target computer and record the machine/compiler details.
- These are standalone reference implementations for the assignment tasks. If your instructor supplied starter files with TODO markers, preserve their required function names/signatures when transferring the logic.
