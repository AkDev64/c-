#!/bin/bash

OUTPUT_FILE="conteudo_concatenado_final.txt"
SCRIPT_NAME="concatenate_files_v3.sh"

# Remove o arquivo de saída se ele já existir para começar do zero
rm -f "$OUTPUT_FILE"

# Itera sobre todos os itens no diretório atual
for file in *; do
  # Verifica se o item é um arquivo (e não um diretório, o arquivo de saída, os scripts ou a.out)
  if [[ -f "$file" && "$file" != "$OUTPUT_FILE" && "$file" != "$SCRIPT_NAME" && "$file" != "a.out" ]]; then
    # Adiciona o cabeçalho com o nome do arquivo
    echo "--- $file ---" >>"$OUTPUT_FILE"
    # Adiciona o conteúdo do arquivo
    cat "$file" >>"$OUTPUT_FILE"
    # Adiciona uma linha em branco para separação
    echo "" >>"$OUTPUT_FILE"
  fi
done

echo "Processo concluído. Todos os arquivos foram concatenados em $OUTPUT_FILE"
