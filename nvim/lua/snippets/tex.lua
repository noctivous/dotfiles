local ls = require("luasnip")
local s = ls.snippet
local t = ls.text_node
local i = ls.insert_node

ls.add_snippets("tex", {
  -- Sections
  s("sec", { t("\\section*{"), i(1, "Titel"), t("}") }),
  s("subsec", { t("\\subsection*{"), i(1, "Titel"), t("}") }),

  -- Itemize / Enumerate
s("it", {
    t({"\\begin{itemize}", "\\item "}), i(1),
    t({"", "\\item "}), i(2),
    t({"", "\\end{itemize}"})
}),
 s("en", {
    t({"\\begin{enumerate}", "  \\item "}),  -- start
    i(1),                                   -- första insättningspunkten
    t({"", "\\end{enumerate}"})             -- avslut
  }),

  -- Inline / Display math
  s("mm", { t("$"), i(1), t("$") }),
  s("dm", { t({"\\[", ""}), i(1), t({"", "\\]"}) }),	
  s("al", {
        t({"\\begin{align*}", ""}),
        i(1),  -- här börjar du skriva dina rader
        t({"", "\\end{align*}"}),
    }),

  -- Definitions / Theorems / Proofs
  s("def", { t("\\textbf{Def:} "), i(1) }),
  s("sats", { t("\\textbf{Sats:} "), i(1) }),
  s("lem", { t("\\textbf{Lemma:} "), i(1) }),
  s("proof", { t({"\\begin{proof}", ""}), i(1), t({"", "\\end{proof}"}) }),
s("cases", {
    t("\\begin{cases}"),
    t({"", "  "}), i(1, "x^2 & x > 0 \\\\"), -- första fallet
    t({"", "  "}), i(2, "0 & x <= 0"),       -- andra fallet
    t({"", "\\end{cases}"}),
}),

  -- Sequences / Sums / Integrals
  s("seq", { t("(a_n)_{n=1}^{\\infty}") }),
  s("sum", { t("\\sum_{"), i(1, "n=1"), t("}^{"), i(2, "N"), t("} "), i(3), t("") }),
  s("int", { t("\\int_{"), i(1), t("}^{"), i(2), t("} "), i(3), t(" \\mathrm{d}"), i(4), t("") }),
s("der", {
  t("\\frac{\\mathrm{d}}{\\mathrm{d}"),
  i(1, "x"),
  t("} "),
  i(2, "f(x)")
}),
s("pder", {
  t("\\frac{\\partial "),
  i(1),
  t("}{\\partial "),
  i(2, "x"),
  t("}")
}),
s("lim", {
  t("\\lim_{"),
  i(1, "x \\to \\infty"),
  t("} "),
  i(2)
}),
s("sin", { t("\\sin\\left("), i(1), t("\\right)") }),
s("cos", { t("\\cos\\left("), i(1), t("\\right)") }),
s("tan", { t("\\tan\\left("), i(1), t("\\right)") }),

  -- Fractions, roots, exponents
  s("frac", { t("\\frac{"), i(1), t("}{"), i(2), t("}") }),
  s("sqrt", { t("\\sqrt{"), i(1), t("}") }),
  s("exp", { t("{"), i(1), t("}^{"), i(2, "x"), t("}") }),

  -- Matrices
  s("mat", { t({"\\begin{bmatrix}", "  "}), i(1), t({"", "\\end{bmatrix}"}) }),
s("lp", {
  t("\\left("), i(1), t("\\right)")
}),
s("lb", {
  t("\\left["), i(1), t("\\right]")
}),
s("lsq", {
  t("\\left["), i(1), t("\\right]_{"), i(2), t("}^{"), i(3), t("}")
}),
s("rb", {
  t("\\tcbox[colframe=red, colback=white, boxrule="),
  i(1, "1pt"),
  t(", sharp corners, on line]{"),
  i(2, "text"),
  t("}")
}),
  -- Common symbols
  s("R", { t("\\mathbb{R}") }),
  s("N", { t("\\mathbb{N}") }),
  s("Z", { t("\\mathbb{Z}") }),
  s("Q", { t("\\mathbb{Q}") }),
  s("C", { t("\\mathbb{C}") }),
  s("cd", { t("\\cdot "), i(1) }),
s(";a", { t("\\alpha") }),
s(";b", { t("\\beta") }),
s(";g", { t("\\gamma") }),
s(";d", { t("\\delta") }),
s(";e", { t("\\epsilon") }),
s(";z", { t("\\zeta") }),
s(";h", { t("\\eta") }),
s(";t", { t("\\theta") }),
s(";i", { t("\\iota") }),
s(";k", { t("\\kappa") }),
s(";l", { t("\\lambda") }),
s(";m", { t("\\mu") }),
s(";n", { t("\\nu") }),
s(";x", { t("\\xi") }),
s(";o", { t("\\omicron") }),
s(";p", { t("\\pi") }),
s(";r", { t("\\rho") }),
s(";s", { t("\\sigma") }),
s(";u", { t("\\tau") }),
s(";f", { t("\\phi") }),
s(";c", { t("\\chi") }),
s(";y", { t("\\psi") }),
s(";w", { t("\\omega") }),
  -- Text snippet
  s("tex", { t("\\text{"), i(1, "här"), t("}") }),
  s("img", {
    t({"\\begin{figure}[h!]", "  \\centering", "  \\includegraphics[width="}),
    i(1, "0.8\\textwidth"),
    t({"]{"}),
    i(2, "bild.png"),
    t({"}", "  \\caption{"}),
    i(3, "Beskrivning"),
    t({"}", "  \\label{fig:"}),
    i(4, "label"),
    t({"}", "\\end{figure}"}),
  }),
})  -- <-- glöm inte denna stängande parantes och klammer
