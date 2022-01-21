class Graph:
    def __init__(self,Nodes):
        self.nodes=Nodes
        self.adj_list={}
        
        for node in self.nodes:
            self.adj_list[node]=[]
    
    def add_edge(self,u,v):
        self.adj_list[u].append(v)
        self.adj_list[v].append(u)
    
    def print_adj_list(self):
        for node in self.nodes:
            print(node+'->'+str(self.adj_list[node]))

nodes = ['A','B','C','D','E']
graph = Graph(nodes)
graph.add_edge('A','B')
graph.add_edge('A','C')
graph.add_edge('B','C')
graph.print_adj_list()
