/*input
1
6
+ 0 0
+ 0 4
+ 4 0
+ 2 2
+ 4 4
- 0 0
*/
#include <bits/stdc++.h>
using namespace std;
#define s second
#define f first
vector<pair<int, int> > *points;
vector<pair<int, int> > *hull;
// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(pair<int, int> p, pair<int, int> q, pair<int, int> r)
{
    int val = (q.s - p.s) * (r.f - q.f) -
              (q.f - p.f) * (r.s - q.s);
 
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
int main()
{
    int t;
    cin>>t;
    while(t--) {
        points= new vector<pair<int, int> >;
        int q;
        cin>>q;
        while(q--) {
            hull= new vector<pair<int, int> >;
            char c;
            int a, b;
            cin>>c>>a>>b;
            if(c=='+') {
                points->push_back(make_pair(a, b));
                points->reserve(10000);
            } else {
                points->erase(std::remove(points->begin(), points->end(), make_pair(a, b)), points->end());
            }

            if(points->size()<=2) {
                cout<<"0.0"<<endl;
            } else {
                int n=points->size();
                int l = 0;
                for (int i = 1; i < n; i++)
                    if (*(points+i)->f < *(points[l]+i)->f)
                        l = i;
                int p = l, q;
                do {
                    hull->push_back(points[p]);
                    hull->reserve(10000);
                     q = (p+1)%n;
                    for (int i = 0; i < n; i++)
                    {
                       if (orientation(points[p], points[i], points[q]) == 2)
                           q = i;
                    }
                    p = q;
             
                } while (p != l);  // While we don't come to first point
             
                double ans=0.0;
                for (int i = 1; i < hull.size()-1; i++) {
                    double a=sqrt((hull[0].f-hull[i].f)*(hull[0].f-hull[i].f)+(hull[0].s-hull[i].s)*(hull[0].s-hull[i].s));
                    double b=sqrt((hull[0].f-hull[i+1].f)*(hull[0].f-hull[i+1].f)+(hull[0].s-hull[i+1].s)*(hull[0].s-hull[i+1].s));
                    double c=sqrt((hull[i].f-hull[i+1].f)*(hull[i].f-hull[i+1].f)+(hull[i].s-hull[i+1].s)*(hull[i].s-hull[i+1].s));
                    double s1=(a+b+c)/2;
                    //cout<<a<<endl<<b<<endl<<c<<endl<<s1<<endl<<endl;
                    ans+=sqrt(s1*(s1-a)*(s1-b)*(s1-c));
                }
                printf("%.1f\n",ans);
            }
            delete hull;
            //hull.clear();
            //vector<int> ().swap(hull);
        }
        delete points;
        //points.clear();
        //vector<int> ().swap(points);
    }
   return 0;
}