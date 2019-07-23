#include <iostream>
#include <cstdlib>
#include <cstdio>
 
using namespace std;
 
//union
int sets[20001];
 
int Find( int x )
{
	if ( x != sets[x] )
		sets[x] = Find( sets[x] );
	return sets[x];
}
//union end
 
int main()
{
    #ifndef file
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
	#endif
	int n,c,x,y;
	while ( scanf("%d",&n) != EOF ) {
		for ( int i = 0 ; i < 2*n ; ++ i )
			sets[i] = i;
		while ( scanf("%d%d%d",&c,&x,&y) && c ) {
			int a1 = Find( x ),a2 = Find( x+n );
			int b1 = Find( y ),b2 = Find( y+n );
			switch( c ) {
				case 1: if ( a1 == b2 ) printf("-1\n");
						else {
							sets[a1] = b1;
							sets[a2] = b2;
						}break;
				case 2: if ( a1 == b1 ) printf("-1\n");
						else {
							sets[a1] = b2;
							sets[a2] = b1;
						}break;
				case 3: if ( a1 == b1 ) printf("1\n");
						else printf("0\n");
						break;
				case 4: if ( a1 == b2 ) printf("1\n");
						else printf("0\n");
						break;
			}
            for(int i = 0; i < 2*n; i++)
            {
                if(i == n)
                    cout << "| ";
                cout << sets[i] << ' ';
            }	
            cout << endl;
		}
	}
	
	return 0;
}
