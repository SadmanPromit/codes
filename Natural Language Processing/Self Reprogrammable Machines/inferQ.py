from transformers import AutoTokenizer, AutoModelForCausalLM, BitsAndBytesConfig
import torch

path = "C:/Users/proom/.cache/huggingface/hub/models--nvidia--Mistral-NeMo-Minitron-8B-Base/snapshots/cc94637b669b62c4829b1e0c3b9074fecd883b74"
quantization_config = BitsAndBytesConfig(
    load_in_8bit=True,
    llm_int8_enable_fp32_cpu_offload=True
)
tokenizer = AutoTokenizer.from_pretrained(path, trust_remote_code=True)
if tokenizer.pad_token is None:
    tokenizer.pad_token = tokenizer.eos_token
model = AutoModelForCausalLM.from_pretrained(
    path,
    device_map="auto",
    quantization_config=quantization_config,
    trust_remote_code=True,
    torch_dtype=torch.float16
)

def generate_chunks(prompt, max_new_tokens, chunk_size):
    inputs = tokenizer(
        prompt, 
        return_tensors="pt", 
        padding=True, 
        truncation=True, 
        max_length=512
    )
    inputs = inputs.to(model.device)
    input_ids = inputs["input_ids"]
    attention_mask = inputs["attention_mask"]
    output_ids = input_ids.clone()
    for _ in range(max_new_tokens // chunk_size):
        outputs = model.generate(
            output_ids,
            max_new_tokens=chunk_size,
            pad_token_id=tokenizer.pad_token_id,
            eos_token_id=tokenizer.eos_token_id,
            attention_mask=attention_mask
        )
        output_ids = outputs[:, -chunk_size:]
    return tokenizer.decode(output_ids[0], skip_special_tokens=True)

prompt = "Hello there"
result = generate_chunks(prompt, max_new_tokens=25, chunk_size=13)
print(result)