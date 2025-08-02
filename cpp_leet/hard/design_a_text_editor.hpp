#pragma once

#include "./../imports.hpp"

class TextEditor
{
private:
    string l, r;

    string get_first_ten(void)
    {
        int n = min(10, (int)this->l.size());

        return this->l.substr((int)this->l.size() - n, (int)this->l.size());
    }

public:
    TextEditor() {}
    
    void addText(string text)
    {
        this->l += text;
    }
    
    int deleteText(int k)
    {
        int n = min(k, (int)this->l.size());

        for (int i = 0; i < n; ++i) this->l.pop_back();

        return n;
    }
    
    string cursorLeft(int k)
    {
        int n = min(k, (int)this->l.size());

        for (int i = 0; i < n; ++i)
        {
            this->r.push_back(this->l.back());
            this->l.pop_back();
        }

        return this->get_first_ten();
    }
    
    string cursorRight(int k)
    {
        int n = min(k, (int)this->r.size());

        for(int i = 0; i < n; ++i)
        {
            this->l.push_back(this->r.back());
            this->r.pop_back();
        }

        return this->get_first_ten();
    }
};

static int _performance_boost_ = []()
{
    ios_base::sync_with_stdio(false),
    cin.tie(0),
    cout.tie(0);
    return 0;
} ();