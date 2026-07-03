from typing import List
from collections import deque

class Solution:
    def findMaxPathScore(self, edges: List[List[int]], online: List[bool], k: int) -> int:
        n = len(online)

        costs = sorted(set(c for _, _, c in edges))
        if not costs:
            return -1

        def check(limit):
            g = [[] for _ in range(n)]
            indeg = [0] * n

            for u, v, w in edges:
                if w < limit:
                    continue
                if u != 0 and u != n - 1 and not online[u]:
                    continue
                if v != 0 and v != n - 1 and not online[v]:
                    continue
                g[u].append((v, w))
                indeg[v] += 1

            q = deque(i for i in range(n) if indeg[i] == 0)
            topo = []

            while q:
                u = q.popleft()
                topo.append(u)
                for v, _ in g[u]:
                    indeg[v] -= 1
                    if indeg[v] == 0:
                        q.append(v)

            INF = 10 ** 30
            dist = [INF] * n
            dist[0] = 0

            for u in topo:
                if dist[u] == INF:
                    continue
                for v, w in g[u]:
                    if dist[u] + w < dist[v]:
                        dist[v] = dist[u] + w

            return dist[n - 1] <= k

        lo, hi = 0, len(costs) - 1
        ans = -1

        while lo <= hi:
            mid = (lo + hi) // 2
            if check(costs[mid]):
                ans = costs[mid]
                lo = mid + 1
            else:
                hi = mid - 1

        return ans