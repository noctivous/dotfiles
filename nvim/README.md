# Neovim Configuration

My personal Neovim configuration, built around **Vimscript with Lua-based plugin configuration**.

The config is intentionally lightweight and fairly traditional. It focuses on a fast terminal-based workflow with LSP, autocompletion, Treesitter, fuzzy finding, LaTeX support, Markdown, snippets, and a handful of quality-of-life features.

> This is a personal configuration rather than a general-purpose distribution.
> Feel free to borrow anything you find useful, but some paths and commands are specific to my setup.

## Features

- 🧠 LSP support for several languages
- 🔍 Telescope fuzzy finding
- 🌳 Treesitter syntax highlighting
- 💡 LSP-powered autocompletion with `nvim-cmp`
- ✂️ LuaSnip snippets
- 📄 LaTeX workflow with VimTeX, `texlab`, `pdflatex` and Zathura
- 📝 Markdown rendering and preview
- 📚 VimWiki
- 🖥️ Integrated terminal with ToggleTerm
- 🌲 NERDTree
- 🎨 Custom `base16` color palette
- 🧹 Goyo distraction-free writing mode
- 🔧 Vim-style window and split navigation
- 🐚 ShellCheck integration
- 🔎 Telescope file searching
- ⌨️ A collection of custom shortcuts and editing helpers

---

## Structure

The important parts of the configuration are:

```text
~/.config/nvim/
├── init.vim
├── shortcuts.vim
├── lua/
│   └── snippets/
│       └── tex.lua
└── plugged/
```

`init.vim` contains the main configuration and plugin setup.

The Lua snippet configuration is kept separately under:

```text
lua/snippets/tex.lua
```

`shortcuts.vim` contains additional personal shortcuts.

---

## Installation

### Requirements

The configuration assumes a Unix-like environment and requires:

- Neovim
- `curl`
- Git
- Node.js + npm
- a C compiler
- `make`
- `ripgrep` *(recommended for Telescope)*
- `shellcheck` *(for the ShellCheck mapping)*
- `pdflatex` *(for LaTeX compilation)*
- `zathura` *(for LaTeX PDF viewing and forward search)*

For Arch Linux, most of the required tools can be installed with:

```bash
sudo pacman -S neovim git curl nodejs npm base-devel ripgrep shellcheck texlive-bin zathura
```

Additional TeX packages may be required depending on your documents.

### Clone the configuration

Back up your existing Neovim configuration first if you have one:

```bash
mv ~/.config/nvim ~/.config/nvim.backup
```

Then clone this repository:

```bash
git clone <repository-url> ~/.config/nvim
```

Start Neovim:

```bash
nvim
```

The configuration automatically downloads **vim-plug** if it is not already installed and starts the plugin installation process.

You can also manually run:

```vim
:PlugInstall
```

After installing the plugins, restart Neovim.

---

## Plugins

### Core / Editing

- [vim-surround](https://github.com/tpope/vim-surround) — manipulate surrounding characters
- [vim-commentary](https://github.com/tpope/vim-commentary) — easy commenting
- [vim-easy-align](https://github.com/junegunn/vim-easy-align) — alignment
- [auto-pairs](https://github.com/jiangmiao/auto-pairs) — automatic brackets
- [vim-be-good](https://github.com/ThePrimeagen/vim-be-good) — Vim movement practice

### UI / Workflow

- [mini.base16](https://github.com/echasnovski/mini.base16) — custom colorscheme
- [goyo.vim](https://github.com/junegunn/goyo.vim) — distraction-free writing
- [toggleterm.nvim](https://github.com/akinsho/toggleterm.nvim) — integrated terminal
- [NERDTree](https://github.com/preservim/nerdtree) — file explorer
- [vimagit](https://github.com/jreybert/vimagit) — Git interface

### Search

- [telescope.nvim](https://github.com/nvim-telescope/telescope.nvim) — fuzzy finder
- [plenary.nvim](https://github.com/nvim-lua/plenary.nvim) — Telescope dependency

### Language / Syntax

- [nvim-treesitter](https://github.com/nvim-treesitter/nvim-treesitter) — syntax highlighting and parsing
- [nvim-treesitter-textobjects](https://github.com/nvim-treesitter/nvim-treesitter-textobjects) — Treesitter-powered text objects

### LSP & Completion

- [nvim-lspconfig](https://github.com/neovim/nvim-lspconfig) — LSP configuration
- [nvim-cmp](https://github.com/hrsh7th/nvim-cmp) — autocompletion
- [cmp-nvim-lsp](https://github.com/hrsh7th/cmp-nvim-lsp) — LSP completion source
- [cmp-buffer](https://github.com/hrsh7th/cmp-buffer) — buffer completion
- [cmp-path](https://github.com/hrsh7th/cmp-path) — filesystem path completion
- [cmp-cmdline](https://github.com/hrsh7th/cmp-cmdline) — command-line completion
- [LuaSnip](https://github.com/L3MON4D3/LuaSnip) — snippets
- [friendly-snippets](https://github.com/rafamadriz/friendly-snippets) — community snippets
- [cmp_luasnip](https://github.com/saadparwaiz1/cmp_luasnip) — LuaSnip completion source

### Markdown

- [markview.nvim](https://github.com/OXY2DEV/markview.nvim) — Markdown rendering
- [render-markdown.nvim](https://github.com/MeanderingProgrammer/render-markdown.nvim) — Markdown rendering
- [markdown-preview.nvim](https://github.com/iamcco/markdown-preview.nvim) — browser-based Markdown preview

### LaTeX

- [VimTeX](https://github.com/lervag/vimtex) — LaTeX editing
- `texlab` — LaTeX language server

### Notes

- [VimWiki](https://github.com/vimwiki/vimwiki) — personal wiki / notes

---

## LSP

The configuration currently sets up the following language servers:

```text
lua_ls
pyright
clangd
bashls
html
cssls
ts_ls
jsonls
gopls
rust_analyzer
texlab
```

Make sure the corresponding language servers are installed on your system.

For example:

```bash
lua-language-server
pyright
clangd
bash-language-server
typescript-language-server
gopls
rust-analyzer
texlab
```

The configuration currently manages these manually rather than through Mason.

---

## Treesitter

Treesitter parsers are enabled for:

```text
C
C++
Lua
Python
Bash
HTML
CSS
JavaScript
JSON
Vim
Markdown
Markdown Inline
YAML
Rust
Go
Haskell
```

They can be updated from Neovim with:

```vim
:TSUpdate
```

---

## Telescope

The main file-search mapping is:

| Key | Action |
|---|---|
| `<leader>ff` | Find files |

The leader key is:

```vim
,
```

So `<leader>ff` becomes:

```text
,ff
```

---

## Keybindings

### Windows

| Key | Action |
|---|---|
| `Ctrl+h` | Move to left window |
| `Ctrl+j` | Move to lower window |
| `Ctrl+k` | Move to upper window |
| `Ctrl+l` | Move to right window |
| `Ctrl+↑` | Increase window height |
| `Ctrl+↓` | Decrease window height |
| `Ctrl+←` | Decrease window width |
| `Ctrl+→` | Increase window width |

### Tabs

| Key | Action |
|---|---|
| `<leader>1` | Go to tab 1 |
| `<leader>2` | Go to tab 2 |

### Tools

| Key | Action |
|---|---|
| `<leader>t` | Toggle terminal |
| `<leader>n` | Toggle NERDTree |
| `<leader>ff` | Telescope file search |
| `<leader>m` | Markdown preview |
| `<leader>v` | Open VimWiki |
| `<leader>f` | Goyo writing mode |
| `<leader>o` | Toggle English spell checking |
| `<leader>s` | Run ShellCheck |
| `<leader>c` | Compile current LaTeX file |
| `<leader>p` | Run `opout` on current file |

---

## Writing Mode

`<leader>f` enables Goyo and changes the background to light mode:

```text
,f
```

This is mainly intended for distraction-free writing.

English spell checking can be toggled with:

```text
,o
```

---

## LaTeX

The configuration has a fairly complete LaTeX workflow.

### Compilation

Press:

```text
,c
```

to save and compile the current `.tex` file with:

```bash
pdflatex -interaction=nonstopmode -halt-on-error
```

The generated PDF can then be opened using:

```text
,p
```

which runs the local `opout` script.

### Forward search

`texlab` is configured to use Zathura for forward search:

```text
Neovim → texlab → Zathura
```

VimTeX is also configured to use Zathura as its PDF viewer.

### Snippets

Custom LuaSnip snippets are loaded from:

```text
~/.config/nvim/lua/snippets/
```

The current configuration includes a TeX snippet file:

```text
lua/snippets/tex.lua
```

Snippets can be expanded or jumped through with:

| Key | Action |
|---|---|
| `Tab` | Expand / jump forward |
| `Shift+Tab` | Jump backward |
| `Ctrl+E` | Change snippet choice |

There is also a small helper for quickly inserting LaTeX environments:

```text
<leader>j
```

---

## Completion

`nvim-cmp` provides completion from:

- LSP
- LuaSnip
- Current buffer

Useful mappings:

| Key | Action |
|---|---|
| `Ctrl+Space` | Open completion |
| `Ctrl+j` | Next completion |
| `Ctrl+k` | Previous completion |
| `Enter` | Confirm completion |

---

## VimWiki

The wiki is configured to use Markdown:

```text
~/lab/vimwiki
```

with:

```text
.md
```

files.

Open the wiki with:

```text
,v
```

---

## Theme

The configuration uses `mini.base16` with a custom palette.

The general aesthetic is intentionally dark, high-contrast and minimal, with a small number of strong accent colors.

The editor background is transparent where possible, allowing the terminal background to show through.

---

## Customization

This configuration is deliberately not designed as a plug-and-play Neovim distribution.

Some parts assume a particular environment, including:

- `$HOME/.config/nvim`
- `~/lab/vimwiki`
- `$BIB`
- `$REFER`
- `opout`
- Zathura
- `pdflatex`
- `shellcheck`

If you want to use the configuration yourself, you will probably want to adjust these paths and commands.

In particular, the following mappings depend on external environment variables:

```text
$BIB
$REFER
```

---

## Notes

This configuration is a work in progress and changes as my workflow evolves.

I prefer keeping the configuration relatively close to vanilla Vim/Neovim rather than building a large abstraction layer around it. There is intentionally a mixture of Vimscript and Lua because the configuration started as a Vim configuration and has gradually adopted Neovim's Lua ecosystem.

If something here looks weird, unnecessarily complicated, or like it belongs in a museum:

**it's probably because it does.**

---

## License

Feel free to use, modify, copy, steal, remix, or otherwise cannibalize anything useful from this configuration.

No guarantees, no support contract, no warranty — just a Neovim config.
