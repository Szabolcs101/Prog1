#include "std_lib_facilities.h"

struct Item {

	string name;
	int iid;
	double value;
};

ostream& operator<<(ostream& os, const Item& it)
{
    return os << it.name << '\t'
              << it.iid << '\t'
              << it.value;
}

istream& operator>>(istream& is, Item& it)
{
    std::string ss;
    int ii;
    double dd;
    is >> ss >> ii >> dd;
    Item itt {ss, ii, dd};
    it = itt;
    return is;
}

class Less_than {
    double val;
public:
    Less_than(double vv) : val{vv} { }
    bool operator()(const Item& x) const { return x.value < val; }
};

class Cmp_by_name {
    string name;
public:
    Cmp_by_name(const string& nn) : name{nn} { }
    bool operator()(const Item& x) const { return x.name == name; }
};

class Cmp_by_iid {
    int iid;
public:
    Cmp_by_iid(int id) : iid{id} { }
    bool operator()(const Item& x) const { return x.iid == iid; }
};

template<typename C>
void print(const C& c, char sep = ' ')
{
    for (const auto& a : c)
        cout << a << sep;
    cout << '\n';
}

int main(){

	const string iname {"Items.txt"};
	ifstream ifs {iname};
	if (!ifs) throw runtime_error("Could not read from file: " + iname);

	vector<Item>vi;
	for(Item i; ifs >> i;)
		vi.push_back(i);

	print(vi, '\n');

	sort(vi.begin(), vi.end(), [](const Item& a, Item& b) {return a.name<b.name;});

	print(vi, '\n');

	sort(vi.begin(), vi.end(), [](const Item& a, Item& b) {return a.iid<b.iid;});

	print(vi, '\n');

	sort(vi.begin(), vi.end(), [](const Item& a, Item& b) {return a.value>b.value;});

	print(vi, '\n');

	Item horse_shoe {"horse shoe", 99, 1.34};

    vi.insert(
            find_if(vi.begin(), vi.end(), Less_than(horse_shoe.value)), horse_shoe);

    Item CanonS400 {"Canon S400", 9988, 499.95};

    vi.insert(
            find_if(vi.begin(), vi.end(), Less_than(CanonS400.value)), CanonS400);

    print(vi, '\n');

    vi.erase(find_if(vi.begin(), vi.end(), Cmp_by_name("cherry")));
    vi.erase(find_if(vi.begin(), vi.end(), Cmp_by_name("pear")));

	print(vi, '\n');

    vi.erase(find_if(vi.begin(), vi.end(), Cmp_by_iid(73)));
    vi.erase(find_if(vi.begin(), vi.end(), Cmp_by_iid(54)));

    print(vi, '\n');

    list<Item> li (vi.size());
    copy(vi.begin(), vi.end(), li.begin());

    print(li, '\n');

 
    li.sort([](const Item& a, const Item& b) { return a.name < b.name; });

    print(li, '\n');

    li.sort([](const Item& a, const Item& b) { return a.iid < b.iid; });

    print(li, '\n');

    li.sort([](const Item& a, const Item& b) { return a.value > b.value; });

    print(li, '\n');

    Item horse {"horse", 99, 1.34};
    li.insert(find_if(li.begin(), li.end(), Less_than(horse.value)), horse);

    Item Canon {"Canon", 9988, 499.95};
    li.insert(find_if(li.begin(), li.end(), Less_than(Canon.value)), Canon);

    print(li, '\n');

    li.erase(find_if(li.begin(), li.end(), Cmp_by_name("cherry")));
    li.erase(find_if(li.begin(), li.end(), Cmp_by_name("pear")));

    print(li, '\n');

    li.erase(find_if(li.begin(), li.end(), Cmp_by_iid(73)));
    li.erase(find_if(li.begin(), li.end(), Cmp_by_iid(54)));

    print(li, '\n');

}