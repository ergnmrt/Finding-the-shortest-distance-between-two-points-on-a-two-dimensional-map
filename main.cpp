
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include <opencv2/opencv.hpp>
int xA, yA, xB, yB;
using namespace std;


harita= imread("harita-kroki.jpeg");

Mat img[a][b]= size(harita);

const int r, t, u, p;
const int n=a; // horizontal harita boyu
const int m=b; // vertical harita boyu
static int map[n][m];
static int yasakli_bolge_map[n][m]; // yasakli bolgeler-bos
static int acik_bolge_map[n][m]; // serbest bolgeler-bos
static int dir_map[n][m]; // gidilecek yol sayýsý
const int dir=8; // herhangi iki bokta arasýnda gidilebilecek yol sayisi--ben sectim

static int dx[dir]={1, 1, 0, -1, -1, -1, 0, 1};
static int dy[dir]={0, 1, 1, 1, 0, -1, -1, -1};

class node
{
    int xPos;  //anlik pozisyon
    int yPos;
    
    int level; //gidilen mesafe
    int priority;  //gidilen ve gidilebilcek tahmini mesafe---1/8 hata ile

    public:
        node(int xp, int yp, int d, int p) 
            {xPos=xp; yPos=yp; level=d; priority=p;}
    
        int getxPos() const {return xPos;}
        int getyPos() const {return yPos;}
        int getLevel() const {return level;}
        int getPriority() const {return priority;}

        void updatePriority(const int & xDest, const int & yDest)
        {
             priority=level+estimate(xDest, yDest)*10; //A* algoritma 
        }

        
        void nextLevel(const int & i) // i: yol
        {
             level+=(dir==8?(i%2==0?10:14):10);
        }
        
        
        const int & estimate(const int & xDest, const int & yDest) const
        {
            static int xd, yd, d;
            xd=xDest-xPos;
            yd=yDest-yPos;         

        
            d=static_cast<int>(sqrt(xd*xd+yd*yd));

            
            return(d);
        }
};
// oncelik hesaplama
bool operator<(const node & a, const node & b)
{
  return a.getPriority() > b.getPriority();
}


string pathFind( const int & xStart, const int & yStart, 
                 const int & xFinish, const int & yFinish )
{
    static priority_queue<node> pq[2]; // acik yollarin listesi
    static int pqi; // 
    static node* n0;
    static node* m0;
    static int i, j, x, y, xdx, ydy;
    static char c;
    pqi=0;

    // haritayi resetle
    for(y=0;y<m;y++)
    {
        for(x=0;x<n;x++)
        {
            closed_nodes_map[x][y]=0;
            open_nodes_map[x][y]=0;
        }
    }

    // harita nokta aramayi baslat
    
    n0=new node(xStart, yStart, 0, 0);
    n0->updatePriority(xFinish, yFinish);
    pq[pqi].push(*n0);
    open_nodes_map[x][y]=n0->getPriority(); // doðru yollari isaretle

    // A* arama
    while(!pq[pqi].empty())
    {
        //en kisa iki nokta arasi mesafeyi bul
        n0=new node( pq[pqi].top().getxPos(), pq[pqi].top().getyPos(), 
                     pq[pqi].top().getLevel(), pq[pqi].top().getPriority());

        x=n0->getxPos(); y=n0->getyPos();

        pq[pqi].pop(); // noktayý izin verilene tasi
        open_nodes_map[x][y]=0;
        // yasaklý bolgeleri isaretle
        closed_nodes_map[x][y]=1;

        // en kýsa yolu bulunca dur
        if(x==xFinish && y==yFinish) //son nokta kordinatý
        {
            //  bulduðun yolu ciz
            string path="";
            while(!(x==xStart && y==yStart))
            {
                j=dir_map[x][y];
                c='0'+(j+dir/2)%dir;
                path=c+path;
                x+=dx[j];
                y+=dy[j];
            }

            // 
            delete n0;
            
            while(!pq[pqi].empty()) pq[pqi].pop();           
            return path;
        }

        
        delete n0; 
    }
    return ""; 


void compute();
int main()
{
    void pixelparameters()
    
  cout << "1 .Bolgenin x kordinatýný giriniz :";
	cin >> x1;
	cout << "2 .Bolgenin y kornidatini giriniz:";
	cin >> y1;
	
   cout << "1 .Bolgenin x kordinatýný giriniz :";
	cin >> x2;
	cout << "2 .Bolgenin y kornidatini giriniz:";
	cin >> y2;
	
	
    cout<<"Start: "<<x1<<","<<y1<<endl;
    cout<<"Finish: "<<x2<<","<<y2<<endl;
    
    // rotayi cikar
    clock_t start = clock();
    string route=pathFind(x1, y1, x2, y2);
    if(route=="") cout<<"Bos rota olusturuldu!"<<endl;
    clock_t end = clock();
    double time_elapsed = double(end - start);
    cout<<"Rotayý hesaplama zamaný (ms): "<<time_elapsed<<endl;
    cout<<"Rota:"<<endl;
    cout<<route<<endl<<endl;

    // rotayý haritada göstermek
    if(route.length()>0)
    {
        int j; char c;
        int x=xA;
        int y=yA;
        map[x][y]=2;
        for(int i=0;i<route.length();i++)
        {
            c =route.at(i);
            j=atoi(&c); 
            x=x+dx[j];
            y=y+dy[j];
            map[x][y]=3;
        }
        map[x][y]=4;
    
        //Rotayi haritada göster
        for(int y=0;y<m;y++)
        {
            for(int x=0;x<n;x++)
                if(map[x][y]==0)
                    cout<<".";
                else if(map[x][y]==1)
                    cout<<"O"; //engeller
                else if(map[x][y]==2)
                    cout<<"S"; //baþlangýc
                else if(map[x][y]==3)
                    cout<<"R"; //rota
                else if(map[x][y]==4)
                    cout<<"F"; //bitis
            img1= Mat(harita,end1);
            imshow("harita",img1);
            cvWaitKey(0);
        }
    }
    getchar(); //  
    return(0);
}
