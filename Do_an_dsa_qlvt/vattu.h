#pragma once

#include <vector>
#include <string>
#include "models.h"

// KHAI BAO NGUYEN MAU HAM
// --- ham hieu chinh bst ---
bool themvattu(NodeVT*&, const Vattu&);
NodeVT* timvattu(NodeVT*, const std:: string&);
bool hieuchinhvattu(NodeVT*, const std:: string&, const std:: string&, const std:: string&);
bool xoavattu(NodeVT*&, const std:: string&); NodeVT* timmin(NodeVT* root);

// --- ham in --- 
void layvattu(NodeVT* root,std:: vector<Vattu>&);
bool sosanhten(const Vattu&, const Vattu&);
void invattu(NodeVT*);

// --- giai phong cay ---
void giaiphongcay(NodeVT*&);
// =========================
