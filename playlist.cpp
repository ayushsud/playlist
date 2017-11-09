#include <iostream>
#include <string>
using namespace std;

class song
{
public:
    string name;
    song *next;
};

class playlist
{
public:
    string name;
    playlist *next;
    song *s;
    playlist()
    {
        song *s = 0;
    }
};
playlist *headP = 0;

class stack
{
public:
    char c[2];
    playlist *ptr;
    string n;
    stack *next;
};
stack *top = 0;

void push(char c[2], playlist *ptr, string n)
{
    stack *x = new stack;
    x->c[0] = c[0];
    x->c[1] = c[1];
    x->ptr = ptr;
    x->n = n;
    x->next = top;
    top = x;
}

void pop()
{
    if (top == 0)
    {
        cout << "\t*****Stack is empty*****\n";
        return;
    }
    stack *ptr = top;
    top = top->next;
    delete ptr;
}

void createPlaylist(string n)
{
    if (headP == 0)
    {
        playlist *x = new playlist;
        x->name = n;
        x->next = headP;
        headP = x;
    }
    else
    {
        playlist *ptr = headP;
        while (ptr->next != 0)
            ptr = ptr->next;
        playlist *x = new playlist;
        x->next = 0;
        ptr->next = x;
        x->name = n;
    }
    char c[2];
    c[0] = 'a';
    c[1] = 'p';
    push(c, (playlist *)0, n);
}

void createPlaylist(string n, int undo)
{
    cout << "\t\t-----Playlist " << n << " created.-----\n";
    if (headP == 0)
    {
        playlist *x = new playlist;
        x->name = n;
        x->next = headP;
        headP = x;
    }
    else
    {
        playlist *ptr = headP;
        while (ptr->next != 0)
            ptr = ptr->next;
        playlist *x = new playlist;
        x->next = 0;
        ptr->next = x;
        x->name = n;
    }
}

void showPlaylist()
{
    if (headP == 0)
    {
        cout << "No available Playlists\n";
        return;
    }
    cout << "\n\t\t---Available Playlists---\n\n";
    playlist *ptr = headP;
    while (ptr != 0)
    {
        cout << ptr->name << endl;
        ptr = ptr->next;
    }
}

playlist *checkPlaylist(string x)
{
    playlist *ptr = headP;
    while (ptr != 0)
    {
        if (x == ptr->name)
            return ptr;
        ptr = ptr->next;
    }
    return (playlist *)1;
}

void deleteplaylist(string x)
{
    int f = 0;
    if (headP->name == x)
    {
        if (headP->s != 0)
        {
            song *p = headP->s;
            for (song *t = p->next; t != 0; p = t, t = t->next)
                delete p;
        }
        playlist *temp = headP;
        headP = headP->next;
        delete temp;
        f = 1;
    }
    else
    {
        playlist *prev = headP;
        playlist *ptr = headP->next;
        while (prev != 0)
        {
            if (ptr->name == x)
            {
                if (ptr->s != 0)
                {
                    song *p = ptr->s;
                    for (song *t = p->next; t != 0; p = t, t = t->next)
                        delete p;
                }
                prev->next = ptr->next;
                delete ptr;
                f = 1;
                break;
            }
            prev = ptr;
            ptr = ptr->next;
        }
    }
    if (f == 0)
    {
        cout << "\t*****No such playlist*****\n";
        return;
    }
    char c[2];
    c[0] = 'd';
    c[1] = 'p';
    push(c, (playlist *)0, x);
}

void deleteplaylist(string x, int undo)
{
    cout << "\t\t-----Playlist " << x << " deleted.-----" << endl;
    int f = 0;
    if (headP->name == x)
    {
        if (headP->s != 0)
        {
            song *p = headP->s;
            for (song *t = p->next; t != 0; p = t, t = t->next)
                delete p;
        }
        playlist *temp = headP;
        headP = headP->next;
        delete temp;
        f = 1;
    }
    else
    {
        playlist *prev = headP;
        playlist *ptr = headP->next;
        while (prev != 0)
        {
            if (ptr->name == x)
            {
                if (ptr->s != 0)
                {
                    song *p = ptr->s;
                    for (song *t = p->next; t != 0; p = t, t = t->next)
                        delete p;
                }
                prev->next = ptr->next;
                delete ptr;
                f = 1;
                break;
            }
            prev = ptr;
            ptr = ptr->next;
        }
    }
    if (f == 0)
    {
        cout << "*****No such playlist*****\n";
        return;
    }
}

bool duplicateplaylist(string x)
{
    for (playlist *ptr = headP; ptr != 0; ptr = ptr->next)
        if (ptr->name == x)
            return 1;
    return 0;
}

void addSong(playlist *activeplaylist, string n)
{
    char c[2];
    c[0] = 'a';
    c[1] = 's';
    push(c, activeplaylist, n);
    song *x = new song;
    x->name = n;
    if (activeplaylist->s == 0)
    {
        x->next = 0;
        activeplaylist->s = x;
        return;
    }
    song *ptr = activeplaylist->s;
    while (ptr->next != 0)
        ptr = ptr->next;
    ptr->next = x;
    x->next = 0;
}

void addSong(playlist *activeplaylist, string n, int undo)
{
    cout << "\t\t-----Song " << n << " added to playlist " << activeplaylist->name << ".-----\n";
    song *x = new song;
    x->name = n;
    if (activeplaylist->s == 0)
    {
        x->next = 0;
        activeplaylist->s = x;
        return;
    }
    song *ptr = activeplaylist->s;
    while (ptr->next != 0)
        ptr = ptr->next;
    ptr->next = x;
    x->next = 0;
}

void displaySongs(playlist *activeplaylist)
{
    song *head = activeplaylist->s;
    if (head == 0)
        cout << "\t-----*****The playlist is empty*****-----\n\n";
    song *ptr = head;
    while (ptr != 0)
    {
        cout << "\t\t\t" << ptr->name << endl;
        ptr = ptr->next;
    }
    cout << endl;
}

bool duplicatesong(playlist *activeplaylist, string n)
{
    if (activeplaylist->s == 0)
        return 0;
    for (song *ptr = activeplaylist->s; ptr != 0; ptr = ptr->next)
        if (ptr->name == n)
            return 1;
    return 0;
}

void deletesong(playlist *activeplaylist, string n)
{
    int f = 0;
    if (activeplaylist->s->name == n)
    {
        song *ptr = activeplaylist->s;
        activeplaylist->s = activeplaylist->s->next;
        delete ptr;
        f = 1;
    }
    else
    {
        song *prev = activeplaylist->s;
        for (song *ptr = activeplaylist->s->next; ptr != 0; prev = ptr, ptr = ptr->next)
        {
            if (ptr->name == n)
            {
                song *t = ptr;
                prev->next = ptr->next;
                delete t;
                break;
            }
        }
        f = 1;
    }
    if (f == 0)
    {
        cout << "\t*****No such song exists****\n";
        return;
    }
    char c[2];
    c[0] = 'd';
    c[1] = 's';
    push(c, activeplaylist, n);
}

void deletesong(playlist *activeplaylist, string n, int undo)
{
    cout << "\t\t-----Song " << n << " deleted.-----" << endl;
    int f = 0;
    if (activeplaylist->s->name == n)
    {
        song *ptr = activeplaylist->s;
        activeplaylist->s = activeplaylist->s->next;
        delete ptr;
        f = 1;
    }
    else
    {
        song *prev = activeplaylist->s;
        for (song *ptr = activeplaylist->s->next; ptr != 0; prev = ptr, ptr = ptr->next)
        {
            if (ptr->name == n)
            {
                song *t = ptr;
                prev->next = ptr->next;
                delete t;
                break;
            }
        }
        f = 1;
    }
    if (f == 0)
    {
        cout << "\t*****No such song exists****\n";
        return;
    }
}

void undo()
{
    if (top == 0)
    {
        cout << "\t*****Stack is empty*****No previous operation.\n";
        return;
    }
    if (top->c[0] == 'd' && top->c[1] == 's')
    {
        addSong(top->ptr, top->n, 1);
        pop();
        return;
    }
    if (top->c[0] == 'a' && top->c[1] == 's')
    {
        deletesong(top->ptr, top->n, 1);
        pop();
        return;
    }
    if (top->c[0] == 'a' && top->c[1] == 'p')
    {
        deleteplaylist(top->n, 1);
        pop();
        return;
    }
    if (top->c[0] == 'd' && top->c[1] == 'p')
    {
        createPlaylist(top->n, 1);
        pop();
        return;
    }
}

void displaystack()
{
    int f = 0;
    for (stack *ptr = top; ptr != 0; ptr = ptr->next)
    {
        cout << "Name=" << ptr->n << "\nPlaylist=" << ptr->ptr << "\nchar=" << ptr->c << endl;
        f++;
    }
    cout << endl
         << "Stack size=" << f << endl;
}

int main()
{
    playlist *s;
    int f, fl;
    char n, x;
    string t;
    while (1)
    {
        f = 0;
        cout << "Enter 1 to create playlist.\nEnter 2 to select a playlist.\nEnter 3 to delete a playlist.\nEnter 4 to exit.\nEnter 5 to undo last operation\n";
        cin >> n;
        switch (n)
        {

        case '1':
            cout << "Enter playlist name\n";
            cin >> t;
            while (duplicateplaylist(t))
            {
                cout << "*****Playlist already exists.Please Enter another playlist name*****\n";
                cin >> t;
            }
            createPlaylist(t);
            cout << "\t---Playlist Created---\n\n";
            break;

        case '2':
            if (headP == 0)
            {
                cout << "\t*****No available playlists*****\n";
                break;
            }
            showPlaylist();
            cout << "Enter playlist name to select\n";
            cin >> t;
            s = checkPlaylist(t);
            if (s == 0)
                cout << "\t---Empty Playlist---\n\n";
            if (s == (playlist *)1)
            {
                cout << "\t---Invalid playlist---\n\n";
                break;
            }
            while (1)
            {
                cout << "\n\t\t\t--***Playlist " << s->name << "***--\n\n";
                fl = 0;
                cout << "\t*Enter 1 to add a song to the playlist.\n\t*Enter 2 to display the playlist.\n\t*Enter 3 to delete a song.\n\t*Enter 4 to go to the previous menu.\n\t*Press 5 to undo last operation\n";
                cin >> x;
                switch (x)
                {
                case '1':
                    cout << "Enter song name\n";
                    cin >> t;
                    while (duplicatesong(s, t))
                    {
                        cout << "*****Song already exists.Please Enter another song name*****\n";
                        cin >> t;
                    }
                    addSong(s, t);
                    break;

                case '2':
                    displaySongs(s);
                    break;

                case '3':
                    displaySongs(s);
                    cout << "Enter song name to delete\n";
                    cin >> t;
                    deletesong(s, t);
                    break;

                case '4':
                    fl = 1;
                    break;

                case '5':
                    undo();
                    break;

                case '6':
                    displaystack();
                    break;

                default:
                    cout << "\tInvalid Choice. Choose again\n\n";
                    break;
                }
                if (fl == 1)
                    break;
            }
            break;

        case '3':
            showPlaylist();
            cout << "Enter playlist name to delete\n";
            cin >> t;
            deleteplaylist(t);
            break;

        case '4':
            f = 1;
            break;

        case '5':
            undo();
            break;

        default:
            cout << "\tInvalid Choice. Choose again\n\n";
        }
        if (f == 1)
            break;
    }
}
