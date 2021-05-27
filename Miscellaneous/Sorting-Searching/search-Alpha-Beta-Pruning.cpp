int max_value(GameTree* root, int alpha, int beta);
int min_value(GameTree* root, int alpha, int beta);
class GameTree {
public:
	vector<GameTree*> children;
	int value;
	GameTree(int v) {
		/* Constructor */
		this->value = v;
	}
	GameTree() {}
};

int max_value(GameTree* root, int alpha, int beta) {
	if (root->children.size() == 0) return root->value;

	int v = INT_MIN;
	for (int i = 0; i < root->children.size(); i++) {
		v = max(v, min_value(root->children[i], alpha, beta));
		if (v >= beta) {
			cout << "Pruned" << endl;
			return v;
		}
		alpha = max(v, alpha);
	}
	
	return v;
}

int min_value(GameTree* root, int alpha, int beta) {	
	if (root->children.size() == 0) return root->value;

	int v = INT_MAX;
	for (int i = 0; i < root->children.size(); i++) {
		v = min(v, max_value(root->children[i], alpha, beta));
		if (v <= alpha) {
			cout << "Pruned" << endl;
			return v;
		}
		beta = min(v, beta);
	}
	
	return v;
}

void minimax(GameTree* root) {
	int alpha = INT_MIN, beta = INT_MAX;
	cout << min_value(root, alpha, beta);
	cout << max_value(root, alpha, beta);
}

int main() {
	GameTree root;
	GameTree a, b, c, d, e, f, g, h, i, j;
	root.children.push_back(&a);
	root.children.push_back(&b);
	root.children.push_back(&c);

	a.children.push_back(&d);
	a.children.push_back(&e);

	b.children.push_back(&f);
	b.children.push_back(&g);

	c.children.push_back(&h);
	c.children.push_back(&i);

	GameTree aa(4), ab(6), ac(7), ad(9), ae(1), af(2), ag(0), ah(1), ai(8), aj(1), ak(9), al(2);

	d.children.push_back(&aa);
	d.children.push_back(&ab);

	e.children.push_back(&ac);
	e.children.push_back(&ad);

	f.children.push_back(&ae);
	f.children.push_back(&af);

	g.children.push_back(&ag);
	g.children.push_back(&ah);

	h.children.push_back(&ai);
	h.children.push_back(&aj);

	i.children.push_back(&ak);
	i.children.push_back(&al);

	minimax(&root);

	return 0;
}
