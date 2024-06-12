#include <iostream>
#include <vector>

// Определение структуры узла дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        if (!root)
            return 0;
        if (root->val < low)
            return rangeSumBST(root->right, low, high);
        if (root->val > high)
            return rangeSumBST(root->left, low, high);
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};

// Вспомогательная функция для добавления узла в дерево
TreeNode* insertIntoBST(TreeNode* root, int val)
{
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    else if (val > root->val)
        root->right = insertIntoBST(root->right, val);
    return root;
}

// Функция для создания дерева из вектора значений
TreeNode* createBST(const std::vector<int>& values)
{
    TreeNode* root = nullptr;
    for (int val : values)
    {
        if (val != -1) // Предполагаем, что -1 обозначает 'null'
        {
            root = insertIntoBST(root, val);
        }
    }
    return root;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    // Пример 1
    std::vector<int> values1 = { 10,5,15,3,7,-1,18 };
    TreeNode* root1 = createBST(values1);
    Solution solution;
    std::cout << "Сумма значений узлов в диапазоне [7, 15]: " << solution.rangeSumBST(root1, 7, 15) << std::endl;

    // Пример 2
    std::vector<int> values2 = { 10,5,15,3,7,13,18,1,-1,6 };
    TreeNode* root2 = createBST(values2);
    std::cout << "Сумма значений узлов в диапазоне [6, 10]: " << solution.rangeSumBST(root2, 6, 10) << std::endl;

    return 0;
}