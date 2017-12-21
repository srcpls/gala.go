//
// gala.go
// board.cpp
//

#include "board.hpp"

board::board()
{
    turn=0;
    
    blackcaptured=0;
    whitecaptured=0;
    
    for(int i=0;i<19;i++)
    {
        for(int j=0;j<19;j++)
        {
            grid[i][j]=0;
        }
    }
    
}

board::~board()
{
    
}

void board::addstone(int i,int j)
{
    if(turn%2==0)
    {
        if(grid[i][j]==0)
        {
            grid[i][j]=1;
            
            turn++;
        }
        else
        {
            std::cout<<"error"<<std::endl;
        }
    }
    else
    {
        if(grid[i][j]==0)
        {
            grid[i][j]=2;
            
            turn++;
        }
        else
        {
            std::cout<<"error"<<std::endl;
        }
    }
    
}

int board::checkliberty(group g)
{
    int liberties=0,i,j;
    coordinate c;
    
    for(int k=0;k<g.retrievenumofcoordinates();k++)
    {
        c=g.retrievecoordinate(k);
        
        i=c.i;
        j=c.j;
        
        if(grid[i-1][j]==0 && i-1>=0 && j>=0 && i-1<19 && j<19)
        {
            liberties++;
        }
        if(grid[i][j-1]==0 && i>=0 && j-1>=0 && i<19 && j-1<19)
        {
            liberties++;
        }
        if(grid[i][j+1]==0 && i>=0 && j+1>=0 && i<19 && j+1<19)
        {
            liberties++;
        }
        if(grid[i+1][j]==0 && i+1>=0 && j>=0 && i+1<19 && j<19)
        {
            liberties++;
        }
    }
    
    return liberties;
}

void board::makegroupnil(group *g)
{
    coordinate makenil;
    for(int i=0;i<g->retrievenumofcoordinates();i++)
    {
        makenil=g->retrievecoordinate(i);
        grid[makenil.i][makenil.j]=0;
    }
    
    std::cout<<"got here"<<std::endl;
    std::cout<<"g->retrievecolor()="<<g->retrievecolor()<<std::endl;
    
    if(g->retrievecolor()==2)
    {
        std::cout<<"         retrieve num of coord for g:"<<g->retrievenumofcoordinates()<<std::endl;
        blackcaptured+=g->retrievenumofcoordinates();
    }
    else if(g->retrievecolor()==1)
    {
        std::cout<<"         retrieve num of coord for g:"<<g->retrievenumofcoordinates()<<std::endl;
        whitecaptured+=g->retrievenumofcoordinates();
    }
    
    std::cout<<"got here too"<<std::endl;
    
    collectofgroups.minusgroup(g);
}

void board::reacttostoneat(int code,int gridi,int gridj)
{
    if(code==0)
    {
        coordinate newcoordinate,findcoordinate;
        newcoordinate.i=gridi;
        newcoordinate.j=gridj;
        newcoordinate.t=turn;
        
        group newgroup(turn%2+1);
        newgroup.addcoordinate(newcoordinate);
        
        if(grid[gridi-1][gridj]==grid[gridi][gridj])
        {
            if(gridi-1>=0 && gridj>=0)
            {
                findcoordinate.i=gridi-1;
                findcoordinate.j=gridj;
                
                
                if(newgroup.hascoordinate(findcoordinate)==-1)
                {
                    collectofgroups.mergegroups(collectofgroups.retrievegroup(collectofgroups.hascoord(findcoordinate)), &newgroup);
                }
            }
        }
        
        if(grid[gridi][gridj-1]==grid[gridi][gridj])
        {
            if(gridi>=0 && gridj-1>=0)
            {
                findcoordinate.i=gridi;
                findcoordinate.j=gridj-1;
                
                if(newgroup.hascoordinate(findcoordinate)==-1)
                {
                    collectofgroups.mergegroups(collectofgroups.retrievegroup(collectofgroups.hascoord(findcoordinate)), &newgroup);
                }
            }
            
        }
        
        if(grid[gridi+1][gridj]==grid[gridi][gridj])
        {
            if(gridi+1<=19 && gridj<=19)
            {
                findcoordinate.i=gridi+1;
                findcoordinate.j=gridj;
                
                if(newgroup.hascoordinate(findcoordinate)==-1)
                {
                    collectofgroups.mergegroups(collectofgroups.retrievegroup(collectofgroups.hascoord(findcoordinate)), &newgroup);
                }
            }
        }
        
        if(grid[gridi][gridj+1]==grid[gridi][gridj])
        {
            if(gridi<=19 && gridj+1<=19)
            {
                findcoordinate.i=gridi;
                findcoordinate.j=gridj+1;
                
                if(newgroup.hascoordinate(findcoordinate)==-1)
                {
                    collectofgroups.mergegroups(collectofgroups.retrievegroup(collectofgroups.hascoord(findcoordinate)), &newgroup);
                }
            }
        }
        
        std::cout<<"newgroup has "<<newgroup.retrievenumofcoordinates()<<"at the end of reacttostoneat"<<std::endl;
        collectofgroups.addgroup(newgroup);
        
        
        
        for(int i=0;i<collectofgroups.retrievenumofgroups();i++)
        {
            if(checkliberty(collectofgroups.retrievegroupat(i))==0)
            {
                makegroupnil(collectofgroups.retrievegroup(i));
            }
        }
    }
    
}

void board::countspacegroups()
{
    int tempgrid[19][19];
    
    for(int i=0;i<19;i++)
    {
        for(int j=0;j<19;j++)
        {
            tempgrid[i][j]=grid[i][j];
        }
    }
    
    
    
    
    int count=3;
    coordinate newcoordinate;
    group newgroup(0);
    
    for(int i=0;i<19;i++)
    {
        for(int j=0;j<19;j++)
        {
            if(grid[i][j]==0)
            {
                newcoordinate.i=i;
                newcoordinate.j=j;
                newgroup.addcoordinate(newcoordinate);
                
                tempgrid[i][j]=count;
                
                if(j==18)
                {
                    spaces.addgroup(newgroup);
                    newgroup.makenilcoordinates();
                    
                    if(grid[i+1][0]==0)
                    {
                        count++;
                    }
                }
            }
            else
            {
                if(newgroup.retrievenumofcoordinates()>0)
                {
                    spaces.addgroup(newgroup);
                    
                    newgroup.makenilcoordinates();
                }
                
                if(grid[i][j+1]==0)
                {
                    count++;
                }
            }
        }
    }
    
    std::vector <int> vect;
    
    for(int j=0;j<19;j++)
    {
        for(int i=0;i<19;i++)
        {
            if(grid[i][j]==0)
            {
                vect.push_back(tempgrid[i][j]-3);
                
                if(i==18)
                {
                    for(int k=1;k<vect.size();k++)
                    {
                        if(vect[0]!=vect[k])
                        {
                            if(vect[k]>=0)
                            {
                            spaces.mergegroups(spaces.retrievegroup(vect[k]), spaces.retrievegroup(vect[0]));
                            
                            for(int m=0;m<19;m++)
                            {
                                for(int n=0;n<19;n++)
                                {
                                    if(tempgrid[m][n]-3==vect[k])
                                    {
                                        tempgrid[m][n]=vect[0]+3;
                                    }
                                    else if(tempgrid[m][n]-3>vect[k])
                                    {
                                        tempgrid[m][n]-=1;
                                    }
                                    
                                    std::cout<<tempgrid[m][n]<<" ";
                                }
                                std::cout<<std::endl;
                            }
                
                            for(int l=k+1;l<vect.size();l++)
                            {
                                if(vect[l]==vect[k])
                                {
                                    vect[l]=vect[0];
                                }
                                else
                                {
                                    vect[l]-=1;
                                }
                            }
                            }
                        }
                    }
                    
                    vect.clear();
                }
            }
            else
            {
                if(vect.size()>0)
                {
                    for(int k=1;k<vect.size();k++)
                    {
                        if(vect[0]!=vect[k])
                        {
                            if(vect[k]>=0)
                            {
                            spaces.mergegroups(spaces.retrievegroup(vect[k]), spaces.retrievegroup(vect[0]));
                            
                            for(int m=0;m<19;m++)
                            {
                                for(int n=0;n<19;n++)
                                {
                                    if(tempgrid[m][n]-3==vect[k])
                                    {
                                        tempgrid[m][n]=vect[0]+3;
                                    }
                                    else if(tempgrid[m][n]-3>vect[k])
                                    {
                                        tempgrid[m][n]-=1;
                                    }
                                    
                                    std::cout<<tempgrid[m][n]<<" ";
                                    
                                }
                                std::cout<<std::endl;
                            }
                            
                            for(int l=k+1;l<vect.size();l++)
                            {
                                if(vect[l]==vect[k])
                                {
                                    vect[l]=vect[0];
                                }
                                else
                                {
                                    vect[l]-=1;
                                }
                            }
                            }}
                    }
                    
                    vect.clear();

                }
            }
        }
    }
    
}

void board::labelgroups()
{
    int count=0,count2=0;
    
    for(int i=0;i<19;i++)
    {
        for(int j=0;j<19;j++)
        {
            if(grid[i][j]==0)
            {
                count2++;
            }
        }
    }
    
    std::cout<<"count2 = "<<count2<<std::endl;
    
    
    int groupnum=1;
    int labgrid[20][20];
    
    for(int i=0;i<19;i++)
    {
        for(int j=0;j<19;j++)
        {
            labgrid[i][j]=0;
        }
    }
    
    coordinate findcoordinate;
    group findgroup(-1);
    
    for(int i=0;i<collectofgroups.retrievenumofgroups();i++)
    {
        findgroup=collectofgroups.retrievegroupat(i);
        
        for(int j=0;j<findgroup.retrievenumofcoordinates();j++)
        {
            findcoordinate=findgroup.retrievecoordinate(j);
            
            labgrid[findcoordinate.i][findcoordinate.j]=groupnum;
        }
        groupnum++;
    }
    
    
    
    
    
    
    groupnum=97;
    
    for(int i=0;i<spaces.retrievenumofgroups() && count<count2;i++)
    {
        findgroup=spaces.retrievegroupat(i);
        
        for(int j=0;j<findgroup.retrievenumofcoordinates();j++)
        {
            findcoordinate=findgroup.retrievecoordinate(j);
            
            labgrid[findcoordinate.i][findcoordinate.j]=groupnum;
            count++;
        }
        groupnum++;
    }
    
    
    char spacechar;
    for(int i=0;i<19;i++)
    {
        for(int j=0;j<19;j++)
        {
            if(grid[i][j]!=0)
            {
                std::cout<<labgrid[i][j]<<" ";
            }
            else
            {
                spacechar=static_cast<char>(labgrid[i][j]);
                std::cout<<spacechar<<" ";
            }
        }
        std::cout<<std::endl;
    }
    
}

void board::printboard()
{
    labelgroups();
    
    std::cout<<std::endl;
    
    for(int i=0;i<19;i++)
    {
        for(int j=0;j<19;j++)
        {
            if(grid[i][j]==1)
            {
                std::cout<<"x"<<" ";
            }
            else if(grid[i][j]==2)
            {
                std::cout<<"o"<<" ";
            }
            else
            {
                std::cout<<"_"<<" ";
            }
        }
        std::cout<<std::endl;
    }
    
}

void board::gradeboard(rules grules)
{
    if(grules==japanese)
    {
        
    }
}

int board::retrievegrid(int i, int j)
{
    return grid[i][j];
}

int board::retrieveturn()
{
    if(turn%2==0)
    {
        return 1;
    }
    
    return 2;
}

void board::passturn()
{
    turn++;
}

int board::retrievenumofgroups()
{
    return collectofgroups.retrievenumofgroups();
}

int board::retrievenumofspacegroups()
{
    return spaces.retrievenumofgroups();
}

int board::retrieveblackcaptured()
{
    return blackcaptured;
}

int board::retrievewhitecaptured()
{
    return whitecaptured;
}

void board::testfunction()
{
    
    group testgroup(-1);
    for(int i=0;i<retrievenumofspacegroups();i++)
    {
        testgroup=spaces.retrievegroupat(i);
        std::cout<<"group "<<i<<"has "<<testgroup.retrievenumofcoordinates()<<" coordinates"<<std::endl;
    }
}
