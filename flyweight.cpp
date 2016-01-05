using namespace std;
#include <iostream>
#include <vector>
#include <map>
class Mesh
{
      int area; int no_of_holes;
};
      
      class Texture {int size; int width;};
      class Color{int color;}; 
      /*
      This is the tree structure as intended by the game
class Tree
{
      Mesh mesh_;
      Texture bark_;
      Texture leaves_;
      Vector position;
      double height;
      double thickness;
      Color 
}
*/

/* we have to maintain a 1000 trees and all 1000 objects of above will be created and has to be 
sent over the bus from CPU to the GPU.

even though there may be thousands of trees in the forest, they mostly look similar
 most of the fields in these objects are the same between all of those instances.
 we can take out all the attributes these trees have in common and move them to a separate class
*/

class TreeModel
{
      public:
      Mesh mesh_;
      
      Texture bark_;
      Texture leaves_;
      TreeModel(Texture bark_, Texture leaves_,Mesh mesh_): bark_(bark_),leaves_(leaves_),mesh_(mesh_)
      {}
      TreeModel()
      {
      }
};

class EvergreenTreeModel : public TreeModel
  {
      
  };
  class DeciduousTreeModel : TreeModel
  {
        
        }    ;
  class Tree
 {
      public:
   TreeModel *model_;
   vector<int> position_;
  double height_;
  double thickness_;
  Color barkTint_;
  Color leafTint_;
};

enum TreeModelType
{ EVERGREEN, DECIDUOUS };

class Game
{
      vector<Tree> trees;
      map<string,TreeModel*> *treeModelMap;
      public:
      Game()
      { 
      }
       void addTree(Tree tree, TreeModelType treeModelType)
      {
            
             switch(treeModelType)
             {
                case EVERGREEN : { 
                      if(treeModelMap->find("EVERGREEN") == treeModelMap->end() )
                      {
                          TreeModel *treeModel = new EvergreenTreeModel();          
                         // treeModelMap->insert(pair<string,TreeModel> ("EVERGREEN", treeModel));                                           
                          tree.model_ = treeModel;
                      }
                      else
                      {
                          TreeModel *treeModel = treeModelMap->find("EVERGREEN")->second;
                          tree.model_ = treeModel;
                      }
                      break;
                 }  
                 case  DECIDUOUS : {
                                            if(treeModelMap->find("DECIDUOUS") == treeModelMap->end() )
                      {
                          TreeModel *treeModel = new EvergreenTreeModel();          
                        //  treeModelMap->insert(pair<string,TreeModel> ("DECIDUOUS", treeModel));                                           
                          tree.model_ = treeModel;
                      }
                      else
                      {
                          TreeModel *treeModel = treeModelMap->find("DECIDUOUS")->second;
                          tree.model_ = treeModel;
                      }
                      break;
                      }
                      default: break;                 
             }
             //tree.model_ = treeModel; 
             trees.push_back(tree);
             
      }
      }
      ;
            
int main()
{
    Game *game = new Game();
    /*
    for(int i=0;i<1000;i++)
    {
            TreeModelType e = EVERGREEN;
            game->addTree(Tree(), e);
    }
    */
    TreeModelType e = EVERGREEN;
    Tree tree;
    game->addTree(tree, e);
    
    return 0;
}
