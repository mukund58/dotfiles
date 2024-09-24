vim.cmd [[packadd packer.nvim]]

return require('packer').startup(function(use)
  -- Packer can manage itself
 	 use 'wbthomason/packer.nvim'

	use({ 'rose-pine/neovim', as = 'rose-pine' })

	vim.cmd('colorscheme rose-pine')
	use( 'nvim-treesitter/nvim-treesitter', { run = ':TSUpdate'})
	use( 'nvim-treesitter/playground')
	use( 'ThePrimeagen/harpoon')
	use( 'mbbill/undotree')
	use {
  'nvim-telescope/telescope.nvim', tag = '0.1.8',
-- or                            , branch = '0.1.x',
  requires = { {'nvim-lua/plenary.nvim'} }
}
end)
