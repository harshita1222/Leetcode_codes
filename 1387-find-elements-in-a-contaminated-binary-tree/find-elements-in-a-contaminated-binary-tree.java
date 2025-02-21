import java.util.HashSet;
import java.util.Set;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}

class FindElements {
    Set<Integer> elements = new HashSet<>();

    public FindElements(TreeNode root) {
        recover(root, 0);
    }

    private void recover(TreeNode node, int val) {
        if (node == null) return;
        node.val = val;
        elements.add(val);
        recover(node.left, val * 2 + 1);
        recover(node.right, val * 2 + 2);
    }

    public boolean find(int target) {
        return elements.contains(target);
    }
}