let mapleader =","
if ! filereadable(system('echo -n "${XDG_CONFIG_HOME:-$HOME/.config}/nvim/autoload/plug.vim"'))
	echo "Downloading junegunn/vim-plug to manage plugins..."
	silent !mkdir -p ${XDG_CONFIG_HOME:-$HOME/.config}/nvim/autoload/
	silent !curl "https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim" > ${XDG_CONFIG_HOME:-$HOME/.config}/nvim/autoload/plug.vim
	autocmd VimEnter * PlugInstall
endif

map ,, :keepp /<++><CR>ca<
imap ,, <esc>:keepp /<++><CR>ca<

call plug#begin(system('echo -n "${XDG_CONFIG_HOME:-$HOME/.config}/nvim/plugged"'))
Plug 'tpope/vim-surround'
Plug 'echasnovski/mini.base16'
Plug 'lervag/vimtex'
Plug 'OXY2DEV/markview.nvim'
Plug 'junegunn/vim-easy-align'
Plug 'akinsho/toggleterm.nvim', {'tag' : '*'}
Plug 'MeanderingProgrammer/render-markdown.nvim'
Plug 'jiangmiao/auto-pairs'
Plug 'nvim-treesitter/nvim-treesitter', {'do': ':TSUpdate'}
Plug 'nvim-treesitter/nvim-treesitter-textobjects'
Plug 'ThePrimeagen/vim-be-good'
"Plug 'agude/vim-eldar'
Plug 'preservim/nerdtree'
Plug 'junegunn/goyo.vim'
Plug 'jreybert/vimagit'
Plug 'vimwiki/vimwiki'
Plug 'tpope/vim-commentary'
Plug 'ap/vim-css-color'
Plug 'iamcco/markdown-preview.nvim', { 'do': 'cd app && npm install' }
" LSP, Autocompletion, and Snippets
Plug 'neovim/nvim-lspconfig'
"Plug 'williamboman/mason.nvim'
"Plug 'williamboman/mason-lspconfig.nvim'
Plug 'hrsh7th/nvim-cmp'
Plug 'rafamadriz/friendly-snippets'
Plug 'hrsh7th/cmp-nvim-lsp'
Plug 'hrsh7th/cmp-buffer'
Plug 'hrsh7th/cmp-path'
Plug 'hrsh7th/cmp-cmdline'
Plug 'L3MON4D3/LuaSnip', {'tag': 'v2.*', 'do': 'make install_jsregexp'}
Plug 'saadparwaiz1/cmp_luasnip'

" Telescope fuzzy finder
Plug 'nvim-lua/plenary.nvim'
Plug 'nvim-telescope/telescope.nvim', { 'tag': '0.1.5' }
call plug#end()

"LUA CONFIGS
lua << EOF
require("luasnip.loaders.from_vscode").lazy_load()
EOF

lua << EOF
-- Mason and LSP setup
--require("mason").setup()
--require("mason-lspconfig").setup {
--  ensure_installed = { "lua_ls", "pyright", "clangd", "bashls", "html", "cssls", "typescript-language-server", "jsonls", "gopls", "rust_analyzer" }
--}
vim.diagnostic.config({ signs = false })

local lspconfig = require("lspconfig")
lspconfig.lua_ls.setup {}
lspconfig.pyright.setup {}
lspconfig.clangd.setup {}
lspconfig.bashls.setup {}
lspconfig.html.setup {}
lspconfig.cssls.setup {}
lspconfig.ts_ls.setup {}
lspconfig.jsonls.setup {}
lspconfig.gopls.setup {}
lspconfig.rust_analyzer.setup {}
lspconfig.texlab.setup {
  settings = {
    texlab = {
      build = {
        executable = "pdflatex",
        args = { "-interaction=nonstopmode", "-halt-on-error", "%f" },
        onSave = false,
      },
      forwardSearch = {
        executable = "zathura",
        args = { "--synctex-forward", "%l:1:%f", "%p" },
      },
      chktex = {
        onOpenAndSave = true,
        onEdit = true,
      },
    },
  },
}
-- Autocompletion
local cmp = require'cmp'
cmp.setup({
  snippet = {
    expand = function(args)
      require('luasnip').lsp_expand(args.body)
    end,
  },
  mapping = cmp.mapping.preset.insert({
    ['<C-Space>'] = cmp.mapping.complete(),
    ['<CR>'] = cmp.mapping.confirm({ select = true }),
    ['<C-j>'] = cmp.mapping.select_next_item(),
    ['<C-k>'] = cmp.mapping.select_prev_item(),
  }),
  sources = cmp.config.sources({
    { name = 'nvim_lsp' },
    { name = 'luasnip' },
  }, {
    { name = 'buffer' },
  })
})

-- Treesitter
require'nvim-treesitter.configs'.setup {
  ensure_installed = { "c", "lua", "python", "bash", "html", "css", "javascript", "json",
    "cpp", "vim", "markdown", "markdown_inline",  "yaml", "rust", "go", "haskell" },
  highlight = {
    enable = true,
    additional_vim_regex_highlighting = false,
  },
}

-- Toggleterm (already in your init)
require("toggleterm").setup({
  shade_terminals = false,
  highlights = {
    Normal = {
      guibg = "NONE",
    },
    NormalFloat = {
      guibg = "NONE",
    },
    FloatBorder = {
      guibg = "NONE",
    },
  },
})

-- Telescope
require('telescope').setup()

-- LaTeX LSP (texlab)
lspconfig.texlab.setup {
  settings = {
    texlab = {
      build = {
        executable = "pdflatex",
        args = { "-interaction=nonstopmode", "-halt-on-error", "%f" },
        onSave = false, -- we keep your <leader>c compile instead
      },
      forwardSearch = {
        executable = "zathura", -- or your preferred PDF viewer
        args = { "--synctex-forward", "%l:1:%f", "%p" },
      },
      chktex = {
        onOpenAndSave = true,
        onEdit = true,
      },
    },
  },
}
EOF

set noswapfile
set noshowcmd
set title
set bg=dark
set mouse=a
set nohlsearch
set clipboard+=unnamedplus
set noruler
set laststatus=2



highlight LineNr guifg=#f82672
highlight CursorLineNr guifg=#f82672
highlight VertSplit guifg=#da0353 guibg=#000000 ctermfg=red ctermbg=black
highlight StatusLineNC ctermfg=gray ctermbg=black guifg=#888888 guibg=NONE
highlight StatusLine ctermfg=white ctermbg=blue guifg=#ffffff guibg=#da035e 

nnoremap c "_c
filetype plugin on
syntax on
set encoding=utf-8
set number relativenumber
set wildmode=longest,list,full
autocmd FileType * setlocal formatoptions-=c formatoptions-=r formatoptions-=o

vnoremap . :normal .<CR>
map <leader>f :Goyo \| set bg=light \| set linebreak<CR>
map <leader>o :setlocal spell! spelllang=en_us<CR>
set splitbelow splitright
map <leader>t :ToggleTerm<CR>
map <leader>n :NERDTreeToggle<CR>
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif
let NERDTreeBookmarksFile = stdpath('data') . '/NERDTreeBookmarks'
inoremap <leader>j <C-R>=InsertBeginEnd()<CR>

function! InsertBeginEnd()
    return "\\begin{}\n\\end{}"
endfunction
nnoremap <C-Up>    :resize +2<CR>
nnoremap <C-Down>  :resize -2<CR>
nnoremap <C-Left>  :vertical resize -2<CR>
nnoremap <C-Right> :vertical resize +2<CR>
inoremap <C-l> <C-o>l
nnoremap <C-h> <C-w>h
nnoremap <C-j> <C-w>j
nnoremap <C-k> <C-w>k
nnoremap <C-l> <C-w>l
tnoremap <C-j> <C-\><C-n><C-w>j
tnoremap <C-k> <C-\><C-n><C-w>k
nnoremap <leader>1 :tabn 1<CR>
nnoremap <leader>2 :tabn 2<CR>ap <C-l> <C-w>l
map Q gq
map <leader>s :!clear && shellcheck -x %<CR>
map <leader>b :vsp<space>$BIB<CR>
map <leader>r :vsp<space>$REFER<CR>
nnoremap S :%s//g<Left><Left>
nnoremap <leader>m <Plug>MarkdownPreview

nnoremap <leader>c :w \| silent !pdflatex -interaction=nonstopmode -halt-on-error %:p > /dev/null 2>&1 &<CR>
"nnoremap <leader>c :w \| !pdflatex %:p<CR>
"map <leader>c :w! \| !compiler "%:p"<CR>
map <leader>p :!opout "%:p"<CR>

autocmd VimLeave *.tex !texclear %

let g:vimwiki_ext2syntax = {'.Rmd': 'markdown', '.rmd': 'markdown','.md': 'markdown', '.markdown': 'markdown', '.mdown': 'markdown'}
map <leader>v :VimwikiIndex<CR>
let g:vimwiki_list = [{'path': '~/lab/vimwiki', 'syntax': 'markdown', 'ext': '.md'}]
autocmd BufRead,BufNewFile /tmp/calcurse*,~/.calcurse/notes/* set filetype=markdown
autocmd BufRead,BufNewFile *.ms,*.me,*.mom,*.man set filetype=groff
autocmd BufRead,BufNewFile *.tex set filetype=tex
let g:vimtex_view_method = 'zathura'

if &diff
    highlight! link DiffText MatchParen
endif

silent! source ~/.config/nvim/shortcuts.vim

set termguicolors
colorscheme default

"luasnip
" press <Tab> to expand or jump in a snippet. These can also be mapped separately
" via <Plug>luasnip-expand-snippet and <Plug>luasnip-jump-next.
imap <silent><expr> <Tab> luasnip#expand_or_jumpable() ? '<Plug>luasnip-expand-or-jump' : '<Tab>'
" -1 for jumping backwards.
inoremap <silent> <S-Tab> <cmd>lua require'luasnip'.jump(-1)<Cr>

snoremap <silent> <Tab> <cmd>lua require('luasnip').jump(1)<Cr>
snoremap <silent> <S-Tab> <cmd>lua require('luasnip').jump(-1)<Cr>

" For changing choices in choiceNodes (not strictly necessary for a basic setup).
imap <silent><expr> <C-E> luasnip#choice_active() ? '<Plug>luasnip-next-choice' : '<C-E>'
smap <silent><expr> <C-E> luasnip#choice_active() ? '<Plug>luasnip-next-choice' : '<C-E>'

"-- load snippets from path/of/your/nvim/config/my-cool-snippets
lua << EOF
require("luasnip.loaders.from_lua").lazy_load({ paths = { "~/.config/nvim/lua/snippets" } })
EOF

nnoremap <leader>ff <cmd>Telescope find_files<CR>

lua << EOF
require('mini.base16').setup({
  palette = {
    base00 = '#000000',   -- background
    base01 = '#000000',   -- sidebar
    base02 = '#DC0033',   -- mainbar
    base03 = '#675160',   -- comments, plus line number
    base04 = '#F6F3E7',   -- mianbar text color
    base05 = '#F6F3E7',   -- huvudtextfärg, normal text (editor-text)
    base06 = '#e0e0e0',   -- ännu ljusare text, tex caretline eller andra accentueringar
    base07 = '#ffffff',   -- ljusaste text, används typ för stark kontrast eller markers

    base08 = '#DD2E44',   -- variable 
    base09 = '#de935f',   -- orange accent, ofta för numbers, constants
    base0A = '#FBFF31',   -- data type
    base0B = '#2E8A57',   -- element, values
    base0C = '#FBE84F',   -- variable
    base0D = '#6E5FD3',   -- blå accent, keywords, functions
    base0E = '#FE4984',   -- conditionals
    base0F = '#F6F3E7',   -- brun/röd accent, för less common highlights, tex deprecated/obsolete elements
  },
})
EOF
highlight Visual cterm=reverse gui=reverse
highlight Normal ctermbg=NONE guibg=NONE
highlight NormalNC ctermbg=NONE guibg=NONE
highlight LineNr ctermbg=NONE guibg=NONE
highlight LineNrAbove ctermbg=NONE guibg=NONE
highlight LineNrBelow ctermbg=NONE guibg=NONE
highlight CursorLineNr ctermbg=NONE guibg=NONE
highlight SignColumn ctermbg=NONE guibg=NONE 
highlight FoldColumn ctermbg=NONE guibg=NONE
