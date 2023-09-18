#include "liveVarsNode.h"

liveVarsNode::liveVarsNode(ASTNode* astnode)
    : node(astnode)
{}

ASTNode* liveVarsNode::getNode()
{
    return node;
}

set<TableEntry*> liveVarsNode::getUse()
{
    return use;
}

set<TableEntry*> liveVarsNode::getDef()
{
    return def;
}

set<TableEntry*> liveVarsNode::getIn()
{
    return in;
}

set<TableEntry*> liveVarsNode::getOut()
{
    return out;
}

set<liveVarsNode*> liveVarsNode::getPredecessors()
{
    return predecessors;
}

set<liveVarsNode*> liveVarsNode::getSuccessors()
{
    return successors;
}

void liveVarsNode::addUse(Identifier* id)
{
    if(!id->getSymbolInfo())
        return;
    use.insert(id->getSymbolInfo());
}

void liveVarsNode::addDef(Identifier* id)
{
    if(!id->getSymbolInfo())
        return;
    def.insert(id->getSymbolInfo());
}

void liveVarsNode::addVars(usedVariables vars)
{
    for(Identifier* id : vars.getVariables(READ))
        addUse(id);
    for(Identifier* id : vars.getVariables(WRITE))
        addUse(id);
}

void liveVarsNode::addPredecessor(liveVarsNode* pred)
{
    predecessors.insert(pred);
}

void liveVarsNode::addSuccessor(liveVarsNode* succ)
{
    successors.insert(succ);
}