{
    description = "Final for CSCI 201 but I'm using nix...";
    inputs = {
        nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
        flake-utils.url = "github:numtide/flake-utils";
    };
    outputs = {
        self,
        flake-utils,
        nixpkgs,
        ...
    }:
        flake-utils.lib.eachDefaultSystem (system: let
            pkgs = import nixpkgs {
                inherit system;
            };
        in {
            formatter = pkgs.alejandra;
            packages.default = pkgs.stdenv.mkDerivation {
                name = "csci-201";
                src = pkgs.nix-gitignore.gitignoreSource [] ./.;
                nativeBuildInputs = with pkgs; [
                    cmake
                ];
                meta.mainProgram = "csci_201_final";
            };
            devShells.default = pkgs.mkShell {
                inputsFrom = [self.packages.${system}.default];
            };
        });
}
