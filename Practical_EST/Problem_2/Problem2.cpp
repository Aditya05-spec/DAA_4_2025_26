class Pair{
    int dist;
    int node;
    Pair(int dist,int node){
        this.dist=dist;
        this.node=node;
    }
}
class Solution {
    public int[] dijkstra(int V, int[][] edges, int src) {
        int[] distMatrix=new int[V];
        Arrays.fill(distMatrix,Integer.MAX_VALUE);
        distMatrix[src] = 0;
        
        ArrayList<ArrayList<Pair>> adj=new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
            
        }
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj.get(u).add(new Pair(wt, v));
            adj.get(v).add(new Pair(wt, u));
        }
        PriorityQueue<Pair> queue = new PriorityQueue<>((a, b) -> a.dist - b.dist);
        queue.offer(new Pair(0, src));
        while(!queue.isEmpty()){
            Pair curr=queue.poll();
            int currDist = curr.dist;
            int node = curr.node;
            for(Pair neigh:adj.get(node)){
                int newDist = currDist + neigh.dist;
                if (newDist < distMatrix[neigh.node]) {
                    distMatrix[neigh.node] = newDist;
                    queue.offer(new Pair(newDist, neigh.node));
                }
            }
        }
        return distMatrix;
    }
}