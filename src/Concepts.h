Concepts.push_back(new Concept("Null concept")); Concepts.push_back(new ConceptBasic("", "std::cout"));
Concepts.push_back(new ConceptBasic("", "<<"));
Concepts.push_back(new ConceptBasic("", "\"Hello World from Conception 2!\""));
Concepts.push_back(new ConceptBasic("", "\" & size of pointer == \""));
Concepts.push_back(new ConceptBasic("", "sizeof")); LastConcept().AddLabel(26);
Concepts.push_back(new ConceptBasic("", "(")); LastConcept().AddLabel(12); LastConcept().AddLabel(15);
Concepts.push_back(new ConceptBasic("", ")")); LastConcept().AddLabel(12); LastConcept().AddLabel(16);
Concepts.push_back(new ConceptBasic("", "void")); LastConcept().AddLabel(26);
Concepts.push_back(new ConceptBasic("", "*"));
Concepts.push_back(new ConceptBasic("", "std::endl"));
Concepts.push_back(new ConceptBasic("", ";"));
Concepts.push_back(new Concept("C++ bracket"));
Concepts.push_back(new ConceptBasic("", "[")); LastConcept().AddLabel(12); LastConcept().AddLabel(15);
Concepts.push_back(new ConceptBasic("", "]")); LastConcept().AddLabel(12); LastConcept().AddLabel(16);
Concepts.push_back(new Concept("C++ opening bracket"));
Concepts.push_back(new Concept("C++ closing bracket"));
Concepts.push_back(new ConceptBasic("", "PrintHi\nWhoa a second line."));
Concepts.push_back(new ConceptBasic("", "return")); LastConcept().AddLabel(26);
Concepts.push_back(new ConceptBasic("", "0"));
Concepts.push_back(new ConceptBasic("", "main"));
Concepts.push_back(new ConceptBasic("", "int")); LastConcept().AddLabel(26);
Concepts.push_back(new ConceptBasic("", "argc"));
Concepts.push_back(new ConceptBasic("", ",")); LastConcept().AddLabel(12);
Concepts.push_back(new ConceptBasic("", "char")); LastConcept().AddLabel(26);
Concepts.push_back(new ConceptBasic("", "argv"));
Concepts.push_back(new Concept("C++ keyword"));
Concepts.push_back(new ConceptBasic("", "iostream"));
Concepts.push_back(new ConceptBasic("Just a random test object", "test"));
Concepts.push_back(new ConceptBasic("", "{")); LastConcept().AddLabel(12); LastConcept().AddLabel(15);
Concepts.push_back(new ConceptBasic("", "}")); LastConcept().AddLabel(12); LastConcept().AddLabel(16);
Concepts.push_back(new ConceptBasic("", "<")); LastConcept().AddLabel(12); LastConcept().AddLabel(15);
Concepts.push_back(new ConceptBasic("", ">")); LastConcept().AddLabel(12); LastConcept().AddLabel(16);
Concepts.push_back(new ConceptBasic("HTML title tag", "title"));
Concepts.push_back(new ConceptCompound("", {FindConcept("<"), 33, FindConcept(">")}));
Concepts.push_back(new ConceptBasic("", "/"));
Concepts.push_back(new ConceptCompound("", {FindConcept("<"), FindConcept("/"), 33, FindConcept(">")}));
Concepts.push_back(new ConceptCompound("", {34, 36}));
