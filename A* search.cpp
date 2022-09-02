#include<bits/stdc++.h>
using namespace std;

enum class state{empty,obstacle,path,start,finish};

const dirdelta[2][4]={{-1,0},{0,-1},{1,0},{0,1}};

int Heuristic(int x1, int y1, int x2, int y2)
{
    return abs(x2-x1) + abs(y2-y1);
}
bool Compare(const vector<int> & node1, const vector<int> & node2)
{
    return (node1[2] + node1[3]) < (node2[2] + node2[3]);
}

void cellsort(vector<vector<int>> *v)
{
  sort(v->begin(), v->end(), Compare);
}

vector<state> parseline(string line)
{
  istringstream ss(line);
  int n;
  int c;
  vector<state> row;
  while(ss>>n>>c and c==',')
  {
    if(n==0) row.push_back(state::empty);
     else
     {
       row.push_back(state::obstacle)
     }
  }
  return row;
  
}
bool CheckValidCell(int x, int y,const vector<vector<state>> & board)
{
    if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size())
    {
        return board[x][y] == state::empty || board[x][y] == state::finish;
    }
    else
    {
        return false;
    }
}

vector<vector<state>> ReadBoard(string path)
{
  vector<vector<state>> board; 
  ifstream file(path);
  string line;
  if(file)
  {
    while(getline(file,line))
    {
      vector<state> row =parseline(line);
      board.push_back(row);
    }
  }
  return board;
}
void AddToOpen(int x, int y, int g, int h,vector<vector<int>> & open,vector<vector<State>> & board)
{  
    vector<int> newnode{x,y,g,h};
    open.push_back(newnode);
    board[x][y] = State::kClosed;
}


void expanding neighbours(const vector<int>& currentnode,vector<vector<int>> & open,vector<vector<State>> & board,const vector<int> & finishpoint )
{
  int c_x = current_node[0];
  int c_y = current_node[1];
    for(int i = 0; i < 4; i++)
    {
        int n_x = dirdelta[i][0] + c_x;
        int n_y = dirdelta[i][1] + c_y;
        if(CheckValidCell(n_x, n_y, board))
        {
            int n_g = currentnode[2] + 1;
            int n_h = heuristic(n_x, n_y, finishpoint[0], finishpoint[1]);
            //cout << n_x << " " << n_y << " " << n_g << " " << n_h <<endl;
            addtoopen(n_x, n_y, n_g, n_y, open, board);
        }
    }
}
  
} 

vector<vector<State>> Search(vector<vector<State>> & board,const vector<int> & startpoint, const vector<int> & finishpoint)
{
  vector<vector<int>> open;
  int h = heuristic(startpoint[0],startpoint[1],finishpoint[0],finishpoint[1]);
  addtoopen();
  while(open.empty!=false)
  {
    cellsort(&open);
    vector<int> currentnode=open.back();
    open.pop_back();
    int c_x = currentnode[0];
    int c_y = currentnode[1];
    board[c_x][c_y] =state::path;
    if(finishpoint[0] == c_x && finishpoint[1] == c_y)
    {
            board[startpoint[0]][startpoint[1]] = state::start;
            board[finishpoint[0]][finishpoint[1]] = state::finish;
            return board;
     }
    expandneighbours(currentnode,open,board,finishpoint);
    cout<<"No path found!"<<endl;
  }
   return vector<vector<state>>{};
 }
string cellstring(state cell) 
{
  switch(cell) 
  {
    case state::obstacle: return "x   ";
    case state::path: return "p   ";
    case state::start: return "S   ";
    case state::finish: return "F   ";
    default: return "0   "; 
  }
}




void printboard(const vector<vector<State>> board)
{
  for(auto &row:board)
  {
    for(auto &col:board)
    {
      cout<<cellstring(col)<<" ";
    }
    cout<<endl;
  }
}

int main()
{
  int startpoint[2]={};
  int finishpoint[2]={};
  auto board=ReadBoard("board.txt");
  auto solution = Search(board, startpoint, finishpoint);
  printboard(solution);
  
}
