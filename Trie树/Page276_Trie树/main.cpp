//
//  main.cpp
//  Page276_Trie树
//
//  Created by 李林 on 2017/2/8.
//  Copyright © 2017年 lee. All rights reserved.
//

#include <iostream>
using namespace std;

const int branchNum = 26;
/*
 Trie树：节点中不设数据域
 每个节点有个标志位表示是否是一个字符串（到字符串的末尾）
 每个节点保存其子女的节点指针
 */
struct Trie_node{
    bool isStr;                 // 记录此处是否构成一个串
    Trie_node *next[branchNum]; // 指向各个子树的指针
    Trie_node() : isStr(false) {
        memset(next, NULL, sizeof(next));
    }
};

class Trie{
public:
    Trie(){
        root = new Trie_node();
    }
    
    void insert(const char* word){
        Trie_node *location = root;
        while(*word){
            if(location->next[*word-'a'] == NULL){  // 不存在则新建立一个节点
                Trie_node *temp = new Trie_node();
                location->next[*word-'a'] = temp;
            }
            location = location->next[*word-'a'];   // 指针向下移动
            word++;
        }
        location->isStr = true;                     // 到达底部，标记为一个串
    }
    
    bool search(char* word){
        Trie_node *location = root;
        while(*word && location){
            location = location->next[*word-'a'];
            word++;
        }
        return (location != NULL && location->isStr);
    }
    
    void deleteTrie(Trie_node *root){
        for(int i=0; i<branchNum; i++){
            if(root->next[i] != NULL)
                deleteTrie(root->next[i]);
        }
        delete root;
    }
    
    Trie_node* getTrie(){
        return root;
    }
    
private:
    Trie_node *root;
};

int main(int argc, const char * argv[]) {
    
    Trie tree;
    tree.insert("hello");
    tree.insert("world");
    bool result = tree.search("world");
    printf("%d", result); 
    
    return 0;
}
