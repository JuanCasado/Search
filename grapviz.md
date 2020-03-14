pkg-config libgvc --cflags
pkg-config libgvc --libs

./graph -K circo -o out

g++ -I/usr/local/Cellar/graphviz/2.42.3/include/graphviz -L/usr/local/Cellar/graphviz/2.42.3/lib  -lgvc -lcgraph -lcdt  graph.cpp -o graph

#include <graphviz/gvc.h>
#include <graphviz/gvplugin.h>
#include <graphviz/cgraph.h>
#include <graphviz/cdt.h>

int main(int argc, char **argv)
{
    Agraph_t *g;
    Agnode_t *n, *m;
    Agedge_t *e;
    GVC_t *gvc;

    /* set up a graphviz context */
    gvc = gvContext();

    /* parse command line args - minimally argv[0] sets layout engine */
    gvParseArgs(gvc, argc, argv);

    /* Create a simple digraph */
    g = agopen("g", Agdirected, 0);
    n = agnode(g, "n", 1);
    m = agnode(g, "m", 1);
    e = agedge(g, n, m, 0, 1);

    /* Set an attribute - in this case one that affects the visible rendering */
    agsafeset(n, "color", "red", "");

    /* Compute a layout using layout engine from command line args */
    gvLayoutJobs(gvc, g);

    /* Write the graph according to -T and -o options */
    gvRenderJobs(gvc, g);

    /* Free layout data */
    gvFreeLayout(gvc, g);

    /* Free graph structures */
    agclose(g);

    /* close output file, free context, and return number of errors */
    return (gvFreeContext(gvc));
}