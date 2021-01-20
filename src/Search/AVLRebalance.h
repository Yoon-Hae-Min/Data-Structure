treeNode *RoateLL(treeNode *rtree);
treeNode *RoateRR(treeNode *rtree);
treeNode *RoateLR(treeNode *rtree);
treeNode *RoateRL(treeNode *rtree);
int GetHeight(treeNode *tree);
int GetHeightDiff(treeNode *tree);
treeNode *Rebalance(treeNode **rTree);


treeNode *RoateLL(treeNode *rtree){
	treeNode *parentNode=rtree;
	treeNode *childNode=GetLeftSubNode(parentNode);
	
	ChangeLeftSubTree(parentNode,GetRightSubNode(childNode));
	ChangeRightSubTree(childNode, parentNode);
	
	return childNode;
}
treeNode *RoateRR(treeNode *rtree){
	treeNode *parentNode=rtree;
	treeNode *childNode=GetRightSubNode(parentNode);
	
	ChangeRightSubTree(parentNode,GetLeftSubNode(childNode));
	ChangeLeftSubTree(childNode, parentNode);
	
	return childNode;
}


treeNode *RoateLR(treeNode *rtree){
	treeNode *parentNode=rtree;
	treeNode *childNode=GetLeftSubNode(rtree);
	
	
	ChangeLeftSubTree(parentNode,RoateRR(childNode));
	return RoateLL(parentNode);
}

treeNode *RoateRL(treeNode *rtree){
	treeNode *parentNode=rtree;
	treeNode *childNode=GetRightSubNode(rtree);
	
	
	ChangeRightSubTree(parentNode,RoateLL(childNode));
	return RoateRR(parentNode);
}

int GetHeight(treeNode *tree){
	int LSubHeight;
	int RSubHeight;
	if(tree==NULL){
		return 0;
	}
	LSubHeight=GetHeight(GetLeftSubNode(tree));
	RSubHeight=GetHeight(GetRightSubNode(tree));
	
	if(LSubHeight>RSubHeight) return LSubHeight+1;
	else return RSubHeight+1;
}

int GetHeightDiff(treeNode *tree){
	int Lheight;
	int Rheight;
	
	if(tree==NULL) return 0;
	Lheight=GetHeight(GetLeftSubNode(tree));
	Rheight=GetHeight(GetRightSubNode(tree));
	
	return Lheight-Rheight;
}

treeNode *Rebalance(treeNode **rTree){
	int HDiff=GetHeightDiff(*rTree);
	
	if(HDiff>1){
		if(GetHeightDiff(GetLeftSubNode(*rTree))>0) *rTree=RoateLL(*rTree);
		else *rTree=RoateLR(*rTree);
	}
	
	if(HDiff<-1){
		if(GetHeightDiff(GetRightSubNode(*rTree))<0) *rTree=RoateRR(*rTree);//부등호;;;;;;
		else *rTree=RoateRL(*rTree);
	}
	
		
	return *rTree;
}